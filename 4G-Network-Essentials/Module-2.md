# **Security Procedures**

## **Network Attachment and Security Functions**

* Using International Mobile Subscriber Identity (IMSI), SIM cards are
  identified in a unique way. IMSI structure is hierarchical. It starts 
  with 3 digits indicating Mobile Country Code (MCC), proceeded by 2 - 3 
  digits that form Mobile Network Code, then a number allocated by the operator
  9 - 10 digits which is called Mobile Subscriber Identification Number (MSIN).

    * A mobile phone structure in IMSI:  3 (MCC) | 2 - 3 (MNC) | 9 - 10 (MSIN) => max 15 digits

* In most cases in 4G, IP address is not allocated statically, it's allocated
  at power-up, during a process called "Attachment".

    * During this process terminal indicates which type of service it wants
    (public access or professional access) notably by specifying the Access Point Name (APN),
    that tells the network which P-gateway to use.

    * As soon as the terminal is up it listens to the beacon channels for the proper
    operator network and when that's found, it sends an attach request message containing
    its IMSI, the message is received by the eNodeB and transmitted to MME. MME checks 
    for subscriber's profile on its database, if not MME tries to verify the subscriber with
    the HSS, then the profile containing the APN, connect parameters are sent back to MME. 

    * IP address allocation is left up to PGWs. So then MME sends a message containing APN to
    SGW and it forwards it to PGW, and then the IP address allocation happens and its sent back 
    through the same route back to MME and to terminal at last.

    * ![img]()

* The Principle Security Mechanisms

    * Fradulent use of the network => Authentication

    * Listening to exchanges => Encryption

    * Modifying messages => Integrity

        * An attacker with a transceiver can change the IP address that was allocated to a terminal
        during the attachment procedure by superposing a signal on the one transmitted by the 
        base station.

    * Tracking/location of the terminal => Temporary identity

        * If an attacker listens to the exchanges on the radio band and detects an IMSI, it knows
        which subscriber is nearby. Therefore we avoid trasnferring IMSI and use a temporary identity.

* Tips

    * The IMSI is an identity related to the subscription. It does not vary over time and it is linked
    to the USIM card. 

    * Each subscription is linked to an IMSI which is globally unique.

    * In 4G, the IP address of a UE is an address dynamically allocated by the PGW when the terminal
    is turned on.

    * epc.tmobile.com can correspond to an APN.

## **Authentication**

* For each subscription is an IMSI and also a 128-bit secret key K that is stored on the USIM and HSS.
  When the UE connects to a network it sends the IMSI and operator checks the secret key without transmitting
  it on the radio band, it uses a cryptographic function and a challange. This challange is a random number 
  RAND coded on a large number of bits. So both HSS and USIM make a calculation using the cryptographic function
  with RAND and secret key K. Then the results of the calculation are sent to HSS and its verified whether it 
  matches HSS calculation or not.

    * ![img]()

    * In 4G, RAND and K key are 128-bits long. The result of the cryptographic function f varies from 32 - 128 bits.
    Each operator can define its own cryptographic function, as long as the size of the result and challange conform 
    to the specifications. 

    * A trusted 3rd party can play the role of the authenticator, the HSS just needs to provide the RAND and Expected
    Result (XRES).

    * Practically terminal never interacts with HSS, It's the MME that plays the role of the authenticator.

    * RAND and XRES form the Authentication Vector. It's disposed after usage so it will never be used again.

    * In this method there is no verification of the network, so a pirate network can play the role of trusted network.

    * In 4G the concept Mutual Authentication means that the network authenticates the terminal and the terminal
      authenticates the network. So a third component is added to authentication vector called Authentication Token
      (AUTN) which contains a cryptographic function g, that gets secret key K and RAND as input. Then at the start
      of the terminal verification, the authentication vector is sent from HSS to MME and then RAND and AUTN is sent
      from MME to terminal, terminal calculates the value of AUTN and if it's correct it sends its result of calculation
      using function f (RES) to MME.

        * ![img]()

        * In this case an attacker can listen to the network and take note of RAND and AUTN, hence posing as network.

    * To make the process more secure, we add a Sequence Number (SQN) to the AUTN so it becomes: AUTN = g(RAND, K, SQN).
      This way by increasing the value of SQN after each authentication, you can never have the same value of AUTN. And this 
      is validated by terminal before calculating the AUTN.

        * ![img]()

* Authentication

    * Based on a secret key, cryptographic functions and random numbers.

    * The secret key is stored in the SIM and the HSS.

    * The secret key is never transmitted in the network.

    * The SIM and the HSS make the same calculation.

    * The authentication is valid when both find the same results.

    * Mutual Authentication

        - Authentication of UE by the network.

        - Authentication of the network by the terminal.

## **Ciphering and Deciphering**

* In networks ciphering is based on XOR (Exclusive OR). The XOR between the clear text and 
  the sequence generated by the sender.

    * Packet N (clear text) XOR Sequence N (ciphering sequence) = Packet N (ciphered data)

    * They all have the same length as clear text.

    * So we need to change the sequence that is used for ciphering after a few uses. To solve
    this challange we use a Ciphering algorithm that has a base key Kenc that is conserved 
    through an entire session which is shared with the receiver. Kenc is calculated using 
    RAND and secert key K. 

    * Since we're using deterministic algorithms, we need to mix it up and make it random somehow, 
    we do so by adding parameters like Packet number, Bearer, Direction and Packet size to the 
    ciphering algorithm. This ciphering algorithm is executed on the mobile terminal and the eNodeB.

    * These algorithms need to be standardized so operators cannot define their own. There are 3 
      algorithms used in 4G:

        - NULL: Does not cipher the data, only used during network test periods.

        - SNOW 3G

        - AES

    * The ciphering algorithms and keys are negotiated during the terminal authentication phase.

* Ciphering (Encryption)

    * Based on a stable encryption key Kenc generated with secret key K and the random number
    used during the authentication.

    * Ciphering sequence specific to each packet generated with Kenc and parameters including a 
    packet counter.

    * Ciphering based on XOR

    * Ciphering and De-ciphering are the same operation.

* Tips

    * Encryption in a 4G network  is based on a symmetric key (in other words the same secret key
    is used for both ciphering and deciphering).

    * In a 4G network, the ciphering operation is as complex as the deciphering operation.

    * The encryption sequence is calculated from a stable Kenc key, a regularly incremented counter 
    and complementary indicators (direction, length, ...).

    * An operator cannot choose its own encryption algorithm, because then the subscriber would not 
    be able to use any terminal.

## **Integrity Control**

* Protection Against Modification

    * A Message Authentication Code (MAC) is derived from the Data Packet using cryptographic hash functions 
    with a length of 32 bits (in LTE networks). So the sender adds this MAC to each data frame sent over the 
    network: Packet + MAC.  Then the receiver recalculates the MAC from the data and compares it with the MAC
    sent by sender.


    * Properties of Hash Functions:

        - Knowing the output of a function does not help in any way or form to find out the input data.

        - The size of the output is always the same and does not depend on the input size.

    * Used only for signaling messages between MME and UE. There is no integrity control for user data in 4G
    networks. The receiver and sender have the same hash function, same key Kint which was negotiated during 
    the authentication phase which is generated by RAND and Ksecret. Just like the ciphering algorithm, MAC
    must be different each time, including when the same message is transmitted twice. Other properties in 
    Integrity algorithm are Packet number, Signaling message, Direction, bearer, ... . The algorithms are 
    implemented in terminal, eNodeB and MME.

    * There are 3 standard algorithms used in 4G:

        - NULL: Test phase

        - SNOW 3G: Compatibility with 3G

        - AES

    * For each session we have one constant Kenc, and one constant Kint. Starting at the sender, the message 
      is first encrypted and then MAC is attached to it.

        * ![img]()

* Integrity Control

    * Only for signaling messages

    * MAC added to each message

    * Computed by both the sender and the reciver

    * With an integrated key generated:

        - With the secret key K

        - With RAND (used for authentication)

    * Same MAC => Integrity is considered as guaranteed.

* Tips

    * In a security context MAC means Message Authentication Code.

    * Integrity control is based on the addition of a code with a reduced length calculated from
    a secret key.

    * A message between MME and UE is first ciphered and then the MAC code is added to it.

## **Key Hierarchy**

* All the security in 4G rests upon the single principle that there is a secret shared key K
between the HSS and UE.

* We need a first key to ensure the ciphering of user data between the UE and the eNodeB, a
second key to cipher signaling data on the same link (UE and eNodeB), and a third key cipher 
messages between the UE and the MME.

* To ensure the integrity of signaling messages, we need a key to protect the exchanges between 
the UE and the eNodeB and a second key between the UE and MME.

* Because of scalability, HSS delegates the generation of these required keys to MMEs. During the
first contact to HSS, it will generate an Access Security Management Entity (ASME) key or Kasme then
this key is sent to MME responsible for the mobile terminal and it's this key that enables MME to 
generate the rest of the keys necessary. The key is only shared with the MME that contacted HSS. 
The identity of the operator is defined by the MCC/MNC pair. MCC and MNC are conisdered when 
generating the Kasme which makes it impossible for another network to use this key.

* After receiving the Kasme key, MME produces another key Kenb from Kasme which is the key that is
given to the current eNodeB that the mobile terminal is attaching. The UE deduces the Kenb from its 
own generated Kasme key. Kasme and Kenb are not used directly to protect exchanges. They're used as 
the base for set of keys to be generated for the Ciphering and Integrity purposes.

* Several keys are generated from Kasme:

    - Knasenc: For Encryption

    - Knasint: For Integrity between the MME and the terminal.

    * Non Access Stratum (NAS) indicates that these keys are between the mobile terminal and MME.

* Keys generated by Kenb:

    - Krrcenc: For Encryption

    - Krrcint: For Integrity between the eNodeB and the terminal

    - Kupenc: For Encryption of user data

    * RRC indicates that these keys are for signaling between eNodeB and the terminal.

    * User Plane (UP): indicates that these keys is for user packets.

* ![img]()

    * The Kasme key is generated using the secret key K, random number RAND, identifying the operator
    MCC/MNC and the SQN number.

* Tips

    * An encryption key cannot be transmitted from the MME of an operator to the MME of another operator
    to minimize the number of requests sent to the HSS.

    * The K_ASME key, which is used to secure exchanges between the UE and the visited network, is 
    calculated by the HSS from the random number used for authentication, from the identity of the
    visited network and from the secret key K.

    * The K_eNB key used to calculate the encryption keys for exchange between the UE and the eNB, is 
    a key calculated from the K_ASME key, which changes each time the UE changes for another eNodeB.

    * The K_eNB is calculated by the UE but also by the MME.

    * The K_RRCenc is calculated by the UE but also by the eNodeB.

## **Temporary Identity**

* During the first exchanges, ciphering is not enabled. So after the authentication has been compeleted
successfully and ciphering is activated on the radio channel, a temporary identifier is assigned to the IMSI,
called Temporary Mobile Subscriber Identity (TMSI). The TMSI is used as identifier for all future communications.

* TMSI is allocated by MME and can be changed frequently depending on the operator's policies. It can be kept 
as long as the UE stays in the same cell or changed each time UE starts a new session. It changes with each MME
change.

* TMSI is 32 bits with a local significance for MME. The same value can be used by two different MMEs for 
two different UEs. Therefore an identifier with global significance is needed.

* Gloabally Unique Temporary UE Identity (GUTI) enables the network to locate the MME that allocated the TMSI.

* GUTI structure:

    * MCC | MNC | MME Group ID | MME Code | TMSI => 80 bits 

* When the terminal attaches to a network, it sends the first message in GUTI in clear text as identifier. The 
MME is the only one that can make the correspondance and find the subscriber's IMSI and the security context. Then  
it can either verify from the former MME or itself the integrity of the message and then enable ciphering on the 
radio link and configure the necessary keys on the eNodeB and thereby protect all messages from the first transmitted 
one on. Here HSS is not contacted.

* Temporary Identity

    * Necessary to prevent a hacker from tracking the location of a UE.

    * TMSI = Temporary Mobile Subscriber Identity

        - Allocated to the UE

        - Chosen by the MME that controls the UE

        - Transferred only after activation of ciphering

        - Can be frequently renewed

    * GUTI = Globally Unique Temporary Identity

        - Necessary to recover the IMSI of the UE in case of change of MME.

* Tips

    * The TMSI is renewed depending on the operator's own policy.

    * The TMSI is assigned by the MME.

    * The GUTI is built by concatenating the TMSI, the identity of the MME in the network and the 
    identity of the network (country code and operator code).

## **Revisiting Attachment**

* Initial Attachment

    * ![img]()

* IP address Allocation

    * ![img]()

    * APN is the PGW that is supposed to be used.
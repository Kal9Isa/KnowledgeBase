# **Modulation**

## **Introduction**

* In electronics and telecommunications, modulation is the process of 
varying one or more properties of a periodic waveform, called the 
carrier signal, with a modulating signal that typically contains 
information to be transmitted.

* A modulator is a device that performs modulation. A demodulator 
(sometimes detector or demod) is a device that performs demodulation, 
the inverse of modulation. A modem (from modulator–demodulator) can 
perform both operations.

## **Analog vs Digital and Other Modulation Types**

* The aim of **analog modulation** is to transfer an analog baseband 
(or lowpass) signal, for example an audio signal or TV signal, over an 
analog bandpass channel at a different frequency

* The aim of **digital modulation** is to transfer a digital bit stream 
over an analog communication channel, for example over the public switched
telephone network (where a bandpass filter limits the frequency range to 
300–3400 Hz) or over a limited radio frequency band.

* Analog and digital modulation facilitate frequency division multiplexing (FDM),
where several low pass information signals are transferred simultaneously over the 
same shared physical medium, using separate passband channels (several different 
carrier frequencies).

* The aim of **digital baseband modulation** methods, also known as line coding, 
is to transfer a digital bit stream over a baseband channel, typically a non-filtered 
copper wire such as a serial bus or a wired local area network.

* The aim of **pulse modulation** methods is to transfer a narrowband analog signal, for 
example, a phone call over a wideband baseband channel or, in some of the schemes, as a 
bit stream over another digital transmission system.

## **Analog Modulation Methods**

* In analog modulation, the modulation is applied continuously in response to the analog 
information signal. 

* Common analog modulation techniques include:

    * Amplitude modulation (AM) (here the amplitude of the carrier signal is 
      varied in accordance with the instantaneous amplitude of the modulating 
      signal)

        * Double-sideband modulation (DSB)

            * Double-sideband modulation with carrier (DSB-WC) (used on the AM radio 
            broadcasting band)

            * Double-sideband suppressed-carrier transmission (DSB-SC)

            * Double-sideband reduced carrier transmission (DSB-RC)

        * Single-sideband modulation (SSB, or SSB-AM)

            * Single-sideband modulation with carrier (SSB-WC)

            * Single-sideband modulation suppressed carrier modulation (SSB-SC)

        * Vestigial sideband modulation (VSB, or VSB-AM)

        * Quadrature amplitude modulation (QAM)

    * Angle Modulation, which is approximately Constant Envelope:

        * Frequency modulation (FM) (here the frequency of the carrier signal is varied 
        in accordance with the instantaneous amplitude of the modulating signal)

        * Phase modulation (PM) (here the phase shift of the carrier signal is varied in 
        accordance with the instantaneous amplitude of the modulating signal)

        * Transpositional Modulation (TM), in which the waveform inflection is modified 
        resulting in a signal where each quarter cycle is transposed in the modulation process. 
        TM is a pseudo-analog modulation (AM). Where an AM carrier also carries a phase variable 
        phase f(ǿ). TM is f(AM,ǿ).

* ![img-fm-am](https://upload.wikimedia.org/wikipedia/commons/a/a4/Amfm3-en-de.gif)

* Constant Envelope

    * is achieved when a sinusoidal waveform reaches equilibrium in a specific system. This happens when negative feedback in a control system, such as in radio automatic gain control or in an amplifier reaches steady state. Steady state, as defined in electrical engineering, occurs after a system becomes settled. To be more specific, control systems are unstable until they reach a steady state. Constant envelope needs to occur for the system to be stable, where there is the least amount of noise and feedback gain has rendered the system steady.

    * Feedback is used to create a feedback signal to control gain, reduce distortion, control output voltage, improve stability or create instability, as in an oscillator. Some examples of constant envelope modulations are as FSK, GFSK, MSK, GMSK and Feher's IJF - All constant envelope modulations allow power amplifiers to operate at or near saturation levels. Although, the power spectrum efficiency of a non-constant amplitude envelope is always higher than that of a constant envelope modulation.

## **Digital Modulation Methods**

* In digital modulation, an analog carrier signal is modulated by a discrete signal. Digital modulation methods can be considered as digital-to-analog conversion and the corresponding demodulation or detection as analog-to-digital conversion. The changes in the carrier signal are chosen from a finite number of M alternative symbols (the modulation alphabet).

    * PSK (phase-shift keying): a finite number of phases are used.
    * FSK (frequency-shift keying): a finite number of frequencies are used.
    * ASK (amplitude-shift keying): a finite number of amplitudes are used.
    * QAM (quadrature amplitude modulation): a finite number of at least two phases and at least two amplitudes are used.


    * Phase-shift keying (PSK)

        * Binary PSK (BPSK), using M=2 symbols

        * Quadrature PSK (QPSK), using M=4 symbols

        * 8PSK, using M=8 symbols

        * 16PSK, using M=16 symbols

        * Differential PSK (DPSK)

        * Differential QPSK (DQPSK)

        * Offset QPSK (OQPSK)

        * π/4–QPSK

    * Frequency-shift keying (FSK)

        * Audio frequency-shift keying (AFSK)

        * Multi-frequency shift keying (M-ary FSK or MFSK)

        * Dual-tone multi-frequency (DTMF)

    * Amplitude-shift keying (ASK)

    * On-off keying (OOK), the most common ASK form

        * M-ary vestigial sideband modulation, for example 8VSB

    * Quadrature amplitude modulation (QAM), a combination of PSK and ASK

        * Polar modulation like QAM a combination of PSK and ASK[citation needed]

    * Continuous phase modulation (CPM) methods

        * Minimum-shift keying (MSK)

        * Gaussian minimum-shift keying (GMSK)

        * Continuous-phase frequency-shift keying (CPFSK)

    * Orthogonal frequency-division multiplexing (OFDM) modulation

        * Discrete multitone (DMT), including adaptive modulation and bit-loading

    * Wavelet modulation

    * Trellis coded modulation (TCM), also known as Trellis modulation

    * Spread-spectrum techniques

        * Direct-sequence spread spectrum (DSSS)

        * Chirp spread spectrum (CSS) according to IEEE 802.15.4a CSS uses pseudo-stochastic coding
        
        * Frequency-hopping spread spectrum (FHSS) applies a special scheme for channel release

## **Additional notes**

* When utilizing an n Hz bandwidth, n symbols can be transferred.

* BPSK uses 1 bit/symbol, QPSK uses 2 bits/symbol and QAM-16 uses 4 bits/symbol.
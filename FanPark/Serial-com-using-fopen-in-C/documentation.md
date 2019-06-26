## **UART**

* Master clock / x = baud rate

* 9600 bps is the most common baud rate used.

* both endpoints should communicate with the same baud rate.

* 8 bits for receive registers.

* UART starts a high voltage, so the start bit goes low if there 
is anything to send.

* stop bits and parity bit can be added aswell.

## **Serial Programming Linux**

### **Introduction**

* As Linux is a multi-user, multi-tasking OS, programs usually 
don't, and are not allowed to access hardware resources like 
serial UARTs directly. Instead the OS provides:

    - Low-level drivers for mapping the device into the file system
    (/dev, /device/ file system entries).

    - The standard system calls for opening, reading, writing, and 
    closing the device.

    - The standard system call for controlling a device.

    - High-level C libraries for controlling the device.

* The low-level driver not only maps the device into a file system 
with the help of the kernel, it also encapsulates the particular 
hardware.

* The important parts of a device name - such as in /dev - are the 
major and minor numbers. The major number distinguishes a serial 
port which is interpreted by the device driver itself.

* Sometimes the minor number will also be used by the device driver
to determine the DCD - Data Carrier Detect - bahavior of the 
hardware flow control signals to be used.

* The typical device names under Unix for serial interfaces are:

    - /dev/ttyxxx

        * Normal, generic access to the device. Used for terminal
        and other serial communication - teletypes.

    - /dev/cuaxxx

        * Legacy device driver with special DCD handling.

        * Used for accessing modem.

    * The xxx part is typically a one or two digit number, or a 
    lowercase letter, starting at 'a' for the first interface.

    * PC-based Unix systems often mimic DOS/Windows naming for the 
    devices and call them `/dev/comxxx`. Linux system generally 
    calls serial ports `/dev/ttySxxx` instead.

* To summarize, when programming for the serial interface of a Unix
system, it is highly advisable to priovide complete configuration 
for the device name. nothing should be hard coded.

* Devices with the name `/dev/ptyxxx` are pseudo terminal devices, 
typically used by GUIs to provide a temrinal emulator.

### **Serial I/O via Terminal I/O**

* The three common terminal APIs are:

    - V7, 4BSD, XENIX style device-specific ioctl-based API.

    - An older one called termio

    - A newer one called termios

* The terminal I/O APIs rely on the standard system calls for 
reading and writing data. 

* They just add functions for controlling and configuring the 
device which is mostly done via the 'ioctl' system call.

* The line-discipline provides the hardware-independent interface 
for the communication between the computer and the terminal device.
It handles things such as editing, job control, and speical 
character interpretation, and performs transformations on the 
incoming and outgoing data.

### **Difference Between open and fopen** 

* The important distinction here is between a C standard `FILE *`
and an OS-specific file descriptor.

* Four main reasons to use `fopen` instead of `open`:

    1- `fopen` provides you with buffering IO that may turn out to 
    be alot faster than what you're doing with `open`.

    2- `fopen` does line ending translation if the file is not 
    opened in binary mode, which can be very helpful if your 
    program is ever ported to a non-Unix environment.

    3- A `FILE *` gives you the ability to use `fscanf` and other 
    stdio functions.

    4- Your code may someday need to be ported to some other 
    platform that only supports ANSI C and does not support the 
    `open` function.

* In places where you are mainly reading or writing a file 
sequentially, the buffering support is really helpful and a big 
speed improvement. But it can lead to some interesting problems in
which data does not end up in the file when you expect it to be 
there.

* `open` is a low-level OS call, `fdopen` converts an OS-level 
file descriptor to the higher level FILE-abstraction of the C 
language. `fopen` calls `open` is the background and gives you a 
FILE-pointer directly.

### **Command to Configure Serial Port Com in OS**

* Using `stty` you can set the parameters in Linux as below:
`stty -F /dev/ttyS0 9600 cs8 -cstopb -parenb`

* Syntax: `stty [-F DEVICE | --file=DEVICE][SETTING]`

* [stty man page](https://linux.die.net/man/1/stty)

* For Windows the following command is used:
`MODE COM4: BAUD=9600 PARITY=n DATA=8 STOP=1`

* One things is that most serial drivers will reset the settings
to the default once the device is closed.

### **C Methods Encountered**

* The C library function `char *gets(char *str)` reads a line from 
  stdin and stores it into the string pointed to by str. It stops 
  when either the newline character is read or when the EOF is 
  reached, whichever comes first.

    * Example

        '''C
            printf("Enter a string: ");
            gets(str);
        '''

* The C library function `int system(const char *command)` passes 
  the command or program name specified by command to the host 
  environment to be executed by the command processor and returns 
  after the command has been completed.

    * The value returned is -1 on error, and the return status of 
    the command otherwise.

    * Example

        '''C
            system("ls -l");
        '''

* `fgetc()` is used to obtain input from a file single character 
  at a time. After reading the character, the file pointer is 
  advanced to next character.

    * If pointer is at the end of file or if an error occurs, EOF 
    file is returned.

    * Example

        '''C
            FILE *fp = fopen("test.txt", "r");
            char c = fgetc(fp);
        '''

* For reading and writing to a text file, we use the functions 
  `fprintf` and `fscanf`, which are the file versions of `printf` 
  and  `scanf`.

    * Functions `fread()` and `fwrite` are used for reading and 
    writing to a file on the disk respectively in case of binary 
    files.

        '''C
            struct threeNum num;
            FILE *fptr;

            fwrite(&num, sizeof(struct threeNum), 1, fptr);
            // fwrite(address_data, size_data, number_data, pointer to the file);

            fread(&num, sizeof(struct threeNum), 1, fptr);
            // fread(address_data, size_data, number_data, pointer to the file);
        '''

* `fseek()` function, seeks the cursor to the given record in the
  file.

    * Example

        '''C
            struct threeNum num;
            FILE *fptr;

            fseek(fptr, -sizeof(struct threeNum), SEEK_END);
            // fseek(FILE * strean, long int offset, int whence)
            // 1. Pointer to the file
            // 2. Position of the record to be found
            // 3. The location where the offset starts
        '''

    * Different Whence in fseek:

        - SEEK_SET: Starts the offset from the beginning of the 
        file.

        - SEEK_END: Starts the offset from the end of the file.

        - SEEK_CUR: Starts the offset from the current location of 
        the cursor in the file.


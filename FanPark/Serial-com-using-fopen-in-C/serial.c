#include <stdio.h>
#include <stdlib.h>
// #include <fcntl.h>      /*File control defintions */
// #include <termios.h>    /*POSIX terminal contorl definitions */
// #include <unistd.h>     /*UNIX standard definitions */
// #include <errno.h>      /*Error number definitions */

int main (){

    char ch;
    // int fd;             /*File descriptor */
    FILE *fp;

    /* Opening the Serial Port */

    system("stty -F /dev/ttyS0 9600 cs8 -cstopb -parenb");
    /* 9600 baud rate, 8 bits, 1 stop bit, no parity */

    fp = fopen("/dev/ttyS0", "r");

    // fd = open("/dev/ttyS0" , O_RDWR | O_NOCTTY | O_NDELAY);    

    /* 0_RDWR  Read/Write aaccess to serial port */
    /* 0_NOCTTY No terminal will control the process */
    /* 0_NDELAY Non-blocking Mode, Does not care about the status
    of DCD line, Open() returns immediately */

    if (fp == NULL)
    {
        perror("Error while opening the file. \n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Port openned successfully! \n");
    
    

    // if (fd == -1) 
    //     printf("\n Error in Opening the port \n");
    // else
    // {
    //     printf("Port Opened Successfully \n");
    // }

    /* Setting the attributes of the serial port using termios structure */

    // struct termios SerialPortSettings;      /* Create the structure */

    // tcgetattr(fd, &SerialPortSettings);     /* Get the current attributes of the Serial port */

    // cfsetispeed(&SerialPortSettings, B9600);    /* Ser Read speed */
    // cfsetospeed(&SerialPortSettings, B9600);    /* Set Write Speed */

    // SerialPortSettings.c_cflag |= CS8;          /* Set the data bits = 8 */

    // if ((tcsetattr(fd, TCSANOW, &SerialPortSettings) != 0))
    //     printf(" EERROR in setting attributes \n");
    // else 
    //     printf("BaudRate = 9600 \n");

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    

    // close(fd);      /* Close the serial port */

    fclose(fp);

    printf("Closed the port successfully! \n");
    
    
    return 0;
   
}

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ev.h>

#define UART_PORT               "/dev/ttyUSB0"
#define UART_SPEED              9600
#define UART_DATA_BIT           8
#define UART_STOP_BIT           1
#define UART_CHECK_BIT          0

typedef struct {
    int fd;
    char uart_buff[256];
}uart_ctrl_t;

/*串口初始化*/
int uart_init(uart_ctrl_t *uart_ctrl, int speed, int data_bit, int stop, int check)
{
    struct termios opt;
    uart_ctrl->fd = open(UART_PORT, O_RDWR | O_NOCTTY | O_NDELAY);
    if (-1 == uart_ctrl->fd) {
        printf("open uart %s failed\r\n", UART_PORT);
        goto err1;
    }
    if (0 != tcgetattr(uart_ctrl->fd, &opt)) {
        goto err2;
    }
    //设置数据位
    opt.c_cflag &= ~CSIZE;
    switch (data_bit) {
        case 5:
            opt.c_cflag |= CS5;
            break;
        case 6:
            opt.c_cflag |= CS6;
            break;
        case 7:
            opt.c_cflag |= CS7;
            break;
        case 8:
            opt.c_cflag |= CS8;
            break;
        default:
            opt.c_cflag |= CS8;
            break;
    }
    //设置停止位
    if (2 == stop) {
        //2个停止位
        opt.c_cflag |= CSTOPB;
    } else {
        //默认1个停止位
        opt.c_cflag &= ~CSTOPB;
    }
    //设置校验位
    switch (check) {
        case 1:
            //奇校验
            opt.c_cflag |= PARENB;
            opt.c_cflag |= PARODD;
            //INPCK打开输入奇偶校验；ISTRIP去除字符的第八个比特
            opt.c_iflag |= (INPCK | ISTRIP);
        case 2:
            //偶校验
            opt.c_cflag |= PARENB;
            opt.c_cflag &= ~PARODD;
            //INPCK打开输入奇偶校验；ISTRIP去除字符的第八个比特
            opt.c_iflag |= (INPCK | ISTRIP);
        default:
            //默认无校验
            opt.c_cflag &= ~PARENB;
            break;
    }
    //设置波特率
     switch (speed) {
        case 19200:
            if (-1 == cfsetispeed(&opt, B19200)) {
                goto err2;
            }
            if (-1 == cfsetospeed(&opt, B19200)) {
                goto err2;
            }
            break;
       case 115200:
            if (-1 == cfsetispeed(&opt, B115200)) {
                goto err2;
            }
            if (-1 == cfsetospeed(&opt, B115200)) {
                goto err2;
            }
            break;
        default:
            //默认9600
            if (-1 == cfsetispeed(&opt, B9600)) {
                goto err2;
            }
            if (-1 == cfsetospeed(&opt, B9600)) {
                goto err2;
            }
            break;
    }
    //部分模式设置
    opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    opt.c_oflag &= ~OPOST;
    opt.c_iflag &= ~(BRKINT | INPCK | ISTRIP | ICRNL| IGNCR | IXON);
    //清除输入输出数据
    tcflush(uart_ctrl->fd, TCIOFLUSH);
    //激活配置生效
    if(0 != tcsetattr(uart_ctrl->fd, TCSANOW, &opt)) {
        goto err2;
    }
    return 0;
err2:
    close(uart_ctrl->fd);
err1:
    return -1;
}

/*串口事件回调*/
static void watcher_uart_cb (struct ev_loop *loop ,struct ev_io *w, int revents)
{
    void *user_data = ev_userdata(loop);
    uart_ctrl_t *uart_ctrl = (uart_ctrl_t *)user_data;
    int bytes = read(uart_ctrl->fd, uart_ctrl->uart_buff, 32);
    if (-1 == bytes) {
        return ;
    }
    /*
        测试demo,此处不够严谨，真实使用需要临时缓冲然后拷贝到处理数据buffer中.
        有时数据传输过多，并不能一次性读完数据就会截断，故最好使用时开一个数据缓存存储，再处理.
    */
    uart_ctrl->uart_buff[bytes] = '\0';
    printf("%s\r\n", uart_ctrl->uart_buff);
    char *res = "OKyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyz\r\n";
    write(uart_ctrl->fd, res, strlen(res)+1);
}

/*事件循环初始化*/
struct ev_loop* main_loop_init(uart_ctrl_t *uart_ctrl)
{
    static struct ev_io uart_watcher;
    struct ev_loop *loop = ev_loop_new(EVBACKEND_EPOLL);
    if (NULL == loop) {
        printf("create loop failed\r\n");
        return NULL;
    }
    //传参
    ev_set_userdata(loop, uart_ctrl);
    //初始化
    ev_io_init (&uart_watcher, watcher_uart_cb, uart_ctrl->fd, EV_READ);
    ev_io_start (loop, &uart_watcher);
    return loop;
}

int main()
{
    uart_ctrl_t uart_ctrl;
    if (0 != uart_init(&uart_ctrl, UART_SPEED, UART_DATA_BIT, UART_STOP_BIT, UART_CHECK_BIT)) {
        printf("uart init failed\r\n");
        return -1;
    }
    struct ev_loop* loop = main_loop_init(&uart_ctrl);
    if (NULL == loop) {
        printf("loop init failed\r\n");
        return -1;
    }
    ev_run(loop, 0);
    close(uart_ctrl.fd);
    return 0;
}

//
// Created by 张虾ang on 16/10/11.
//
#include <iostream>
#include <fcntl.h>

#define FIFO_SERVER "/tmp/fifoserver"

int main(int argc, char **argv) {
    char read_buffer[4096 * 2];
    int fd;
    int read_size;
    int ret_size;
    read_size = atoi(argv[1]);
    printf("读取字节数为: %d\n", read_size);
    memset(read_buffer, 0, sizeof(read_buffer));

    fd = open(FIFO_SERVER, O_RDONLY | O_NONBLOCK, 0);//打开有名管道 也就是一个文件
    //fd=open(FIFO_SERVER,O_RDONLY,0);//阻塞式

    if (fd < 0) {
        printf("开启有名管道发生错误\n");
        exit(0);
    }
    while (1) {
        memset(read_buffer, 0, sizeof(read_buffer));
        ret_size = read(fd, read_buffer, read_size);//只是开启管道的方式不一样  读取数据还是一样的
        if (ret_size == -1)
            if (errno == EAGAIN)
                printf("没数据可读\n");
        printf("real read bytes %d\n", ret_size);
        sleep(1);
    }
    pause();
    unlink(FIFO_SERVER);

    return 1;
}
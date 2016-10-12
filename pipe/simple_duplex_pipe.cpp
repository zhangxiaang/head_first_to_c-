//
// Created by 张虾ang on 16/10/11.
// 创建两个单向管道合作实现双向管道
//

#include <iostream>

int main() {
    int pipe_in[2];
    int pipe_out[2];

    char write_buff[4096];
    char read_buff[4 * 4];
    memset(write_buff, 'a', sizeof(write_buff));

    pid_t pid;
    if (pipe(pipe_in) < 0 || pipe(pipe_out) < 0) {
        printf("创建管道发生异常\n");
        return -1;
    }
    //每个进程有俩管道了
    if ((pid = fork()) == 0) {
        close(pipe_in[0]);
        close(pipe_out[1]);
        //子进程中关掉负责写入管道的读端和负责读出管道的写端
        int res11 = dup2(pipe_in[1], STDOUT_FILENO);
        printf("res11:%d\n", res11);
        int res22 = dup2(pipe_out[0], STDIN_FILENO);
        printf("res22:%d\n", res22);
        close(pipe_in[1]);
        close(pipe_out[0]);
    } else {
        close(pipe_in[1]);
        close(pipe_out[0]);
        write(pipe_out[1], write_buff, sizeof(write_buff));
        close(pipe_out[1]);
        read(pipe_in[0], read_buff, sizeof(read_buff));
        printf("lalala: %s \n", read_buff);
        close(pipe_in[0]);
    }
    return 1;
}
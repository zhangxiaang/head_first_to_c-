//
// Created by 张虾ang on 16/10/11.
//

#include <iostream>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char r_buff[4];
    char *w_buff;
    int write_num;
    memset(r_buff, 0, sizeof(r_buff));

    if (pipe(pipe_fd) < 0) {
        printf("创建管道错误\n");
        return -1;
    }

    if ((pid = fork()) == 0) {
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        sleep(10);//子进程的读写段都关闭了
        exit(0);
    } else if (pid > 0) {
        sleep(1);
        close(pipe_fd[0]);//关掉读端
        w_buff = (char *) "aaron";
        write_num = (int) write(pipe_fd[1], w_buff, 10);//这个时候所有进程的读端都关闭了 所以此刻的写入无意义(必须要保证有一个进程的读端是开启的)
        if (write_num == -1) {
            printf("向管道写入错误\n");
        } else {
            printf("写入管道的字节数为: %d \n", write_num);
        }
        //最终导致pipe broken异常
        close(pipe_fd[1]);
    }
    return 1;
}
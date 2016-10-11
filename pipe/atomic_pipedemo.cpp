//
// Created by 张虾ang on 16/10/11.
//

#include <iostream>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char read_buffer[4096];
    char write_buffer[4096 * 2];
    int write_num = 0;
    int read_num = 0;

    memset(read_buffer, 0, sizeof(read_buffer));
    memset(write_buffer, 0, sizeof(write_buffer));

    if (pipe(pipe_fd) < 0) {
        printf("创建管道错误\n");
        return -1;
    }

    if ((pid = fork()) == 0) {
        close(pipe_fd[1]);//关闭写端
        while (1) {
            sleep(1);
            read_num = (int) read(pipe_fd[0], read_buffer, 1000);
            printf("子进程读取的字节数为: %d\n", read_num);//可能每次不能保证一次性写完4096个字节才进行读取  可能在写入一半的数据就被打断了
        }//只要读完了buffer区域 就关闭?
        close(pipe_fd[0]);
        exit(0);
    } else if (pid > 0) {
        close(pipe_fd[0]);
        memset(read_buffer, 0, sizeof(read_buffer));//再次clear read_buffer
        if ((write_num = (int) write(pipe_fd[0], write_buffer, 1000)) == -1) {
            printf("写入数据出现错误\n");
        } else {
            printf("写入的字节数为: %d \n", write_num);
        }
        write_num = write(pipe_fd[1], write_buffer, 4096);
        close(pipe_fd[1]);
    }
    return 1;
}
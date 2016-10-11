//
// Created by 张虾ang on 16/10/11.
//

#include <iostream>

int handle_cmd(int cmd);

int main() {
    //todo 父进程传入命令到子进程 子进程执行
    int pipe_fd[2];
    pid_t pid;
    char read_buff[4];
    char *write_buff[256];
    bool childexit = 0;

    memset(read_buff, 0, sizeof(read_buff));

    if (pipe(pipe_fd) < 0) {
        printf("pipe create error\n");
        return -1;
    }

    if ((pid = fork()) == 0) {
        //子进程中不断的读取父进程写入的command
        printf("\n");
        close(pipe_fd[1]);
        sleep(2);
        while (!childexit) {
            int res = read(pipe_fd[0], read_buff, sizeof(read_buff));
            printf("read_num:%d\n", res);
            int cmd = atoi(read_buff);
            if (cmd == 0) {
                printf("命令解析错误请输入正确的命令\n");
                childexit = true;
            } else if (handle_cmd(cmd) != 0) {
                return 1;
            }
            sleep(1);
        }
        close(pipe_fd[0]);
        exit(0);
    } else if (pid > 0) {
        //父进程负责的就是不断的在管道中写入command
        close(pipe_fd[0]);
        write_buff[0] = "003";
        write_buff[1] = "005";
        write_buff[2] = "111";
        write_buff[3] = "333";

        for (int i = 0; i < 4; ++i) {
            write(pipe_fd[1], write_buff[i], 4);
        }

        close(pipe_fd[1]);
    }
    return 1;

}

int handle_cmd(int cmd) {
    switch (cmd) {
        case 3:
            printf("命令为:3");
            return 0;
        case 5:
            printf("命令为:5");
            return 0;
        case 111:
            printf("命令为:111");
            return 0;
        case 333:
            printf("命令为:333");
            return 0;
        default:
            return -1;
    }
}
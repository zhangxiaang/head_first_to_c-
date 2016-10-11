//
// Created by 张虾ang on 16/10/10.
// 验证下管道的读写规则
//

#include <iostream>

int main() {
    int pipe_fd[2];//fd[0]是读端  fd[1]是写端
    pid_t pid;
    char read_buff[100];
    char write_buff[4];

//    char *p_wbuf;//指向write_buff
    int read_num;

    //memset()函数是给数组结构体快速清零的最快的方式
    memset(read_buff, 0, sizeof(read_buff));//把read_buff区的前size大小个的字节全部都使用0填充
    memset(write_buff, 0, sizeof(read_buff));
//    memset(write_buff, 0, sizeof(write_buff));

//    p_wbuf = write_buff;

    if (pipe(pipe_fd) < 0) {//在一个进程中创建出管道 然后在本进程中关掉这个管道的读端 从写端写入write_buff内容
        //在新开辟的子进程中关掉这个管道的写端，只负责从管道中读取内容
        printf("pipe create error\n");
        return -1;
    }
    //产生的协同就是
    if ((pid = fork()) == 0) {
        printf("\n");
        close(pipe_fd[1]);//关掉写端
        sleep(3);
        printf("子进程sleep3s结束\n");
        read_num = (int) read(pipe_fd[0], read_buff, 100);//一次读取的buffer用长度100来存储  超过了的呢?
//        read_num = (int) read(pipe_fd[0], read_buff, 2);//超过的话就只能用长度为2的buffer装满返回了
        printf("read num is %d  the data read from the pipe is %d\n", read_num,
               atoi(read_buff));//注意atoi()是把string转化成int
//        printf("read num is %d  the data read from the pipe is %s\n", read_num, read_buff);
        close(pipe_fd[0]);
        exit(0);
    } else if (pid > 0) {
        printf("子进程的pid:%d\n", pid);
        close(pipe_fd[0]);//在父进程中关掉读端
        strcpy(write_buff, "1111");
        if (write(pipe_fd[1], write_buff, 5) != -1) {
            printf("parent write over\n");
        }
        close(pipe_fd[1]);
        printf("parent close fd[1] over\n");
        sleep(10);
    }
    return 1;
}
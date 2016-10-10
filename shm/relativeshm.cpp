//
// Created by 张虾ang on 16/10/10.
//

#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct people {
    char name[4];
    int age;
};

int main(int argc, char *argv[]) {
    people *p_map;
    p_map = (people *) mmap(NULL, sizeof(people) * 10, PROT_READ | PROT_WRITE,
                            MAP_SHARED | MAP_ANON, -1, 0);
    if (fork() == 0) { //fork表示程序在此处分叉 括号内部都是子进程读取共享内存内容
        printf("1: pid:%d,ppid:%d\n", getpid(), getppid());
        sleep(2);
        for (int i = 0; i < 5; ++i) {
            printf("child read: the %d people's age is %d\n", i + 1, (*(p_map + i)).age);
        }
        (*p_map).age = 100;
        munmap(p_map, sizeof(people) * 10);
        exit(0);
    }
    printf("2: pid:%d,ppid:%d\n", getpid(), getppid());
    char temp = 'a';
    for (int j = 0; j < 5; ++j) {
        temp += j;
        memcpy((*(p_map + j)).name, &temp, 2);
        (*(p_map + j)).age = 20 + j;
    }
    printf("before parentProcess sleep: parent read: the first people,s age is %d\n", (*p_map).age);
    sleep(5);
    printf("after parentProcess sleep:parent read: the first people,s age is %d\n", (*p_map).age);
    printf("umap\n");
    munmap(p_map, sizeof(people) * 10);
    printf("umap ok\n");
    return 1;
}
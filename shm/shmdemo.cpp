//
// Created by 张虾ang on 16/10/10.
// 使用共享内存 创建一个内存区域 映射到A B区域中
//

#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

struct people {
    char name[4];
    int age;
};

int main(int argc, char *argv[]) {
    int fd, i;
    people *p_map;
    char temp;

    fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 00777);
    lseek(fd, sizeof(people) * 5 - 1, SEEK_SET);
    write(fd, "", 1);

    p_map = (people *) mmap(NULL, sizeof(people) * 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);//这一步干了啥
    close(fd);

    temp = 'A';
    for (int j = 0; j < 10; ++j) {
        temp += 1;
        memcpy((*(p_map + j)).name, &temp, 2);//memcpy是做甚的
        (*(p_map + j)).age = 20 + j;
    }
    printf("初始化完成\n");
    sleep(10);//seconds
    munmap(p_map, sizeof(p_map) * 10);//释放和共享内存的连接
    printf("释放和共享内存的连接\n");

    return 0;
}
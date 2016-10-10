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

    fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 00777);//打开参数列表指定的file
    lseek(fd, sizeof(people) * 5 - 1, SEEK_SET);
    printf("people的size为:%d \n", (int) sizeof(people));
    write(fd, "Aaron", 1);

    p_map = (people *) mmap(NULL, sizeof(people) * 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("系统自动给p_map选择的addr为:%p \n", &p_map);//页内存地址

    //mmap()第一个参数为start的位置,代表讓系統自動選定地址，映射成功後返回該地址
    close(fd);

    temp = 'A';
    for (int j = 0; j < 10; ++j) {
        temp += 1;
        memcpy((*(p_map + j)).name, &temp, 2);//把temp地址开头的连续几个字节写入到(*(p_map + j)).name里面
        (*(p_map + j)).age = 20 + j;

        printf("p_map->%d:addr为:%p \n", j, &*(p_map + j));
    }
    printf("初始化完成\n");
    sleep(10);//seconds

    //再次输出内容  看看在sleep期间内容是否被修改了

    for (int i = 0; i < 10; i++) {
        printf("name: %s age %d;\n", (*(p_map + i)).name, (*(p_map + i)).age);
    }//果然 在sleep期间通过process2修改了p_map指向的共享内存区域内容也相应的修改了i == 9 的情况
    munmap(p_map, sizeof(p_map) * 10);//释放和共享内存的连接
    printf("释放和共享内存的连接\n");

    return 0;
}
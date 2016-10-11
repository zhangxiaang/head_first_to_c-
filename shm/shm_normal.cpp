//
// Created by 张虾ang on 16/10/10.
//

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

struct people {
    char name[4];
    int age;
};

int main(int argc, char *argv[]) {
    int fd, i;
    people *p_map;
    fd = open(argv[1], O_CREAT | O_RDWR, 00777);
    p_map = (people *) mmap(NULL, sizeof(people) * 10, PROT_READ | PROT_WRITE,
                            MAP_SHARED, fd, 0);
//    int tempAge = 99;
    char name[] = {'A', 'a', 'n', 'o'};
    for (i = 0; i < 10; i++) {
        printf("name: %s age %d;\n", (*(p_map + i)).name, (*(p_map + i)).age);
        if (i == 9) {
            memcpy((*(p_map + i)).name, &name, 4);
        }
    }

    munmap(p_map, sizeof(people) * 10);
    return 1;
}
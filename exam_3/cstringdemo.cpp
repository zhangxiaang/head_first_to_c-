//
// Created by 张虾ang on 16/10/17.
//

#include <iostream>

using std::string;

//比较两个string
int compares(char *s1, int s1_len, char *s2, int s2_len) {
    int l = s1_len >= s2_len ? s1_len : s2_len;
    for (int i = 0; i < l; ++i) {
        if (*s1 > *s2) {//比较ascii码值的吧?
            return 1;
        } else if (*s1 < *s2) {
            return -1;
        }
        s1 += 1;
        s2 += 1;
    }
    return 0;
}

//遍历string
void iterators(char *s1, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << *s1 << std::endl;
        s1 += 1;
    }
}

//遍历char[]
void iteratorchar(const char *beg, int leng) {
    for (int i = 0; i < leng; ++i) {
        std::cout << *beg << std::endl;
        beg += 1;

    }
}
//合并两个char


int main() {
    char ch[] = {'a', 'b', '+', '+'};
    std::cout << strlen(ch) << std::endl;//why it passed?

    string s = "ahahaaa";
    string s1 = "ahahabb";

    std::cout << (s > s1) << std::endl;
    std::cout << &s << std::endl;
    std::cout << &s1 << std::endl;

    const char *ch1 = "aabs";
    const char *ch2 = "babbs";

    std::cout << ch1 << std::endl;
    std::cout << ch2 << std::endl;
    //前者比较的是const指针的addr 的整型值
    std::cout << (ch1 < ch2) << std::endl;
    //下面比较的是cstring的char 的 ascaii码值
    std::cout << (strcmp(ch1, ch2) < 0) << std::endl;

    std::cout << s + s1 << std::endl;
//    std::cout << &ch1 + &ch2 << std::endl;
    char temp = 's';
    char *temptr = &temp;
    strcat(temptr, ch1);//相对来讲比较危险

//    std::cout << temp << std::endl;
//    std::cout << ch1 << std::endl;

//    std::cout << compares(&s, &s1) << std::endl;
    iterators(&s[0], sizeof(s) / sizeof(int));
    std::cout << compares(&s[0], sizeof(s) / sizeof(int), &s1[0], sizeof(s1) / sizeof(int)) << std::endl;

    iteratorchar(&ch1[0], sizeof(ch1) / sizeof(char));

    char x = 'x';
    char *a = &x;

    strcat(a, ch2);//给某一个char添加const char*
    std::cout << a << std::endl;
    return 1;
}
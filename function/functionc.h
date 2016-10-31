//
// Created by 张虾ang on 16/10/27.
// 尝试在 header文件里面存放function
//
#include <string.h>

using std::string;

#ifndef C_PRIMER_PLUS_FUNCTIONC_H
#define C_PRIMER_PLUS_FUNCTIONC_H

#endif //C_PRIMER_PLUS_FUNCTIONC_H

int add(int a, int b) {
    return a + b;
}

int jiechen(int n) {
    if (n == 1 || n == 0)
        return 1;
    else return n * jiechen(n - 1);
}

bool compare(string &s1, string &s2) {
    s1 = s1 + "2131231231";
    return s1.size() < s2.size();
}

//这个方法好 一下子能够返回多个result 利用传递引用参数也会被影响到实际值的方式
int indexOfStringAndCounts(string &string1, char target, int &counts) {
    for (char c:string1) {
        if (c == target) {
            ++counts;
        }
    }
    int first_index = string1.find_first_of(target);
    return first_index;
}
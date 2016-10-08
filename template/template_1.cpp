//
// Created by 张虾ang on 16/10/6.
//
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
T compares(const T &i1, const T &i2) {
    if (i1 < i2)return T(-1);
    else if (i1 > i2) return T(1);
    else return T(0);
}
//以上就是一个标准的模版函数

int main() {
    vector<int> c1(1, 3);
    vector<int> c2(0, 4);//元组是怎么比较的?
    cout << compares(5, 9) << endl;
}
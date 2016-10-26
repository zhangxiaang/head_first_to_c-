//
// Created by 张虾ang on 16/10/25.
//
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;


int main() {
    int ia[2][3] = {1, 2, 3, 4, 5, 6};//实际上ia是一个大小为2的数组每一个元素是含有3个int的数组

    int (*ia_p)[3] = ia;

    cout << *(*ia_p) << endl;//1
    cout << *(*ia_p) + 1 << endl;
    cout << *(*ia_p) + 2 << endl;
    //实际上因为两个数组是一块儿连续的内存地址所以才可以访问到 如果分开的话肯定是访问不到的
//    cout << *(*ia_p) + 3<< endl;
//    cout << *(*ia_p) + 4<< endl;

    cout << **(ia_p + 1) << endl;//4
    cout << **(ia_p + 1) + 1 << endl;
    cout << **(ia_p + 1) + 2 << endl;
    cout << "---------" << endl;

    //method1
    int rows = sizeof(ia[2]) / sizeof(int);
    int lines = sizeof(ia) / sizeof(int) / rows;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < lines; ++j) {
            cout << ia[j][i] << endl;
        }
    }

    //pointer

//    for (int *p:ia) {
//        cout << *p << endl;
//    }

    for (int k = 0; k < rows * lines; ++k) {
        cout << *(*ia + k) << endl;
    }
    cout << "---------" << endl;
    for (auto &row:ia) {//记住  这个row是一个存储着三个元素的数组对象 也就是说多维数组就是一个以数组为单位的存储结构
        for (auto &elements:row) {
            cout << elements << endl;
        }
    }
    return 1;
}
//
// Created by 张虾ang on 16/11/1.
//

#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

//参考标准库的做法 传递首尾item的引用
void iter_array(const int *beg, const int *end) {
    while (beg <= end) {
        cout << *beg << endl;
        beg++;
    }
}

//通过传递数组的尺寸来遍历数组
void iter_array_2(const int *ptr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *ptr << endl;
        ptr++;
    }
}

int find_bigger(int *a1, int a2) {
    if (*a1 >= a2) {
        return *a1;
    } else
        return a2;
}

void exchange_ptr(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

typedef int arr[10];
using arr = int[10];

arr *getTenElements() {
    return NULL;
}

//那么如果说参数列表是一个未知长度的 或者是可变的 如何处理呢?
//其次考虑一下initializer_list这个标准库 限定时参数类型都是一样的

//void printf(...) {
//    //但是如何遍历到params呢?
//    cout << "sizeof(at) / sizeof(int)" << endl;
//}

void printf(const int *beg, const int *end) {
    while (*beg <= *end) {
        cout << *beg << endl;
        beg++;
    }
}

int main(int args, char **params) {
    //args 是参数数组的长度
    cout << "args:" << args << "params:" << *params << endl;

    int array[5] = {1, 2, 3, 4, 5};
    iter_array(&array[0], &array[4]);
    iter_array_2(array, sizeof(array) / sizeof(int));

    int param1 = 10;
    int param2 = 11;

    int res = find_bigger(&param1, param2);
    cout << "bigger is:" << res << endl;

    int *c1 = &param1;
    int *c2 = &param2;
    cout << "before exchange c1,c2:" << *c1 << "~" << *c2 << endl;
    exchange_ptr(c1, c2);
    cout << "after exchange c1,c2:" << *c1 << "~" << *c2 << endl;

//    printf(1, 2, 3, 4);

    std::initializer_list<int> lists{11, 12, 13, 14, 15, 16};//initializer_list里面的原素都是常量值无法被改变
    printf(lists.begin(), lists.end());
    return 1;
}
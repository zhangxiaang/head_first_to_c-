//
// Created by 张虾ang on 16/10/14.
//
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;


bool compare(auto s1, auto s2, auto s3) {
    for (; s1 != s2; ++s1, ++s2) {

    }
}

int main() {
    int a[] = {1, 2};
    int (*P)[2] = &a;//P指向一个含2个char的数组

    vector<int> int_v(2);
    for (int val : a) {
        int_v.push_back(val);
    }//array copy into vector

//    cout << &*a << endl;
//    cout << &a[0] << endl;
//    cout << *&a[1] << endl;//return ascii code value
//    cout << *&a[2] << endl;

    int *beg = &a[0];

    int size = sizeof(a) / sizeof(int);
    cout << size << endl;
    cout << *(beg) << endl;
    cout << *(beg + 1) << endl;
    cout << *(beg + 2) << endl;

    int last = *(a + 1);//从下标为0移1位
    cout << last << endl;

    int p = a[0];
    int p2 = a[1];

    p += p2 - p;
    cout << p << endl;

    //利用pointer置空array
    int *ptr = a;
    *ptr = 0;
    *(ptr + 1) = 0;

//    cout << a << endl;
    cout << a[0] << endl;
    cout << a[1] << endl;

//    int arr1[5]{1, 2, 3, 4, 5};
//    int arr2[5]{1, 2, 3, 4, 5};
//
//    int *p1 = arr1;
//    int *p22 = arr2;
//    bool result = compare(p1, p22);

    int aaa[] = {1, 2};
    int bbb[] = {1, 2};
//    aaa = bbb;//bbb意味着数组的首元素的地址
    if (std::equal(std::begin(aaa), std::end(aaa), std::begin(bbb))) {
        printf("equal\n");
    } else
        printf("noooo\n");
    return 1;
}
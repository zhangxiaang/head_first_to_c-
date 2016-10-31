//
// Created by 张虾ang on 16/10/26.
//
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

void change1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
//    cout <<"after change"<< " a:" << a << " b:" << b << endl;
}

void change2(int *a, int *b) {
    cout << "aaa" << a << endl;
    cout << "bbb" << b << endl;
//    int *a = &a; 可以理解为a指针指向参数a的地址值
    int temp = *a;//所以这个temp就相当于把&a的引用解除 取出内存地址里面的val
    *a = *b;//指向的是addr指向的值
    cout << "aaa" << a << endl;
    *b = temp;

    cout << "bbb" << b << endl;
}

void change_2(int a, int b) {
    cout << a << endl;
    cout << b << endl;
}

//传递引用  其实就是让&a 和 a 绑定在一起,也就是&a是a的另外一个代表 相互作用
void change3(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void test(int *ptr) {
    *ptr = 0;
    cout << "&ptr" << &ptr << endl;
    cout << "ptr" << ptr << endl;
}

void test2(int *ptr) {
    ptr = 0;//直接吧ptr指向的地址设置为0了
    cout << "---------" << endl;
    cout << "&ptr" << &ptr << endl;
    cout << "ptr" << ptr << endl;
}

void func_const(const int cons) {
    cout << cons << endl;
}

//在调用func_const()函数的时候会自动的忽略掉const修饰符 所以这样导致了下方的method编译不通过
//void func_const(int cons) {
//    cout << cons << endl;
//}

bool find_upper_char(const string &str) {
    for (char c:str) {
        if (isupper(c)) {
            c = '_';
            return true;
        }
    }
    return false;
}

bool find_and_change_upper_char(string &str) {
    for (char &c:str) {
        if (isupper(c)) {
            c = '_';
            return true;
        }
    }
    return false;
}

int main() {
    int a = 1, b = 10;
    change1(a, b);//只是值传递  没有影响到实际的交换
    cout << "after change1" << " a:" << a << " b:" << b << endl;

    change2(&a, &b);//地址传递
    cout << "after change2" << " a:" << a << " b:" << b << endl;
    change_2(*&a, *&b);//*其实就是解引用的作用  *&a <--> a
    change_2(a, b);//*其实就是解引用的作用  *&a <--> a


    change3(a, b);//引用传递
    cout << "after change3" << " a:" << a << " b:" << b << endl;


    int val = 100;
    int val2 = 1000;
    int val3 = 10000;

    test(&val);
    test2(&val2);
    cout << val << endl;
    cout << val2 << endl;

    func_const(val3);

    string string1("12A237asdasjhkj");

    cout << find_upper_char(string1) << endl;
    cout << string1 << endl;//可见 在传递了常量的引用过去后 是无法修改到本身的值的 指示了read_only

    find_and_change_upper_char(string1);
    cout << string1 << endl;
    return 1;
}

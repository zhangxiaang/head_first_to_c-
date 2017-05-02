//
// Created by 张虾ang on 16/11/8.
// 比较迷惑的是 类函数中为何添加const呢?
// 官方解释是说 函数名后面添加const是为了强调this的是一个指向常量的指针,保证每次都不会被改动
//

#include "Sales_data.h"
#include "Implements.h"

#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

//具体在这里完成func的逻辑代码
double Sales_data::avg_price() {
    this->price += 1.11;
    return this->getPrice();
}
//所以也可以在外部添加一个自定义的构造函数 不过还是需要写好抽象函数
Sales_data::Sales_data(const string &i, const double &val) : bookno(i), price(val) {}

int main() {
    Sales_data data;//正式的使用这个class
    double val = 1.23;

    data.setPrice(val);
    cout << data.getPrice() << endl;
    //return this 形成chain调用 return &即可
    data.getAddress().getAddress().getAddress();
    cout << data.getPrice() << endl;
    cout << data.avg_price() << endl;
    //读取地址
//    cout << &data.getAddress() << endl;
//    cout << (&data.getAddress() + 1) << endl;
//    cout << sizeof(data.getISBN()) << endl;

    //如何在类的外部定义函数呢?

    Implements test;
    cout << test.add(1, 2) << endl;
    cout << test.multi(2, 3) << endl;
    //可见这个多继承的点在这里还是好用的
    Sales_data test2;
    test2.setPrice(3.21);
    cout << test2.getPrice() << endl;

    return 1;
}
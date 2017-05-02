//
// Created by 张虾ang on 16/11/8.
//

#ifndef C_PRIMER_PLUS_SALES_DATA_H
#define C_PRIMER_PLUS_SALES_DATA_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Sales_data {

    Sales_data(const string &i) : bookno(i) {};

    //构造函数模式基本为 ClassName(params list): param1(list[0]),...,paramN(list[N]){}
//    Sales_data(const string &i, const double &val) : bookno(i), price(val) {}
    //构造函数? 西沟函数?
public:
    Sales_data(const string &i, const double &val);

    string getISBN() const { return bookno; }


    Sales_data() = default;

public:
    void setPrice(double val) {
        this->price = val;
    }

public:
    double getPrice() {
        return this->price;
    }

public:
    Sales_data &getAddress() {
        this->price += 1;
        return *this;
    }
//即使说这里把变量放到了方法的后面依然是可以访问到的因为
//在编译的时候优先编译的是变量 然后才是方法
private:
    string bookno;
    double price;

public:
    double avg_price();
};


#endif //C_PRIMER_PLUS_SALES_DATA_H

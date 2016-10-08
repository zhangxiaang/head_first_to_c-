//
// Created by 张虾ang on 16/9/28.
//

#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::shared_ptr;

struct person {
    string bookName;
    int age;
    string name;
    int sex;
};

class Person {
public:
    int age;
    string name;
    int sex;
    string bookName;
};

int main() {
    //如何模拟一个野指针
    Person *person_1 = new Person;
    person_1->name = "Aaron";
    int a = 10;
    cout << person_1 << endl;//是person对象的地址值
    cout << &person_1 << endl;//是指针的地址值
    delete person_1;//为什么没有删除呢?
    cout << person_1 << endl;
    printf("--------------\n");
    int *pp = NULL;
    {
        int a = 10;
        pp = &a;
        cout << pp << endl;
        cout << *pp << endl;
    }
    cout << pp << endl;
    cout << *pp << endl;
    printf("--------------\n");
    //智能指针的用法
    shared_ptr<string> ptr(new string("Aaron"));
    string *h = ptr.get();//只是取出来并不会增加ref
    shared_ptr<string> t1 = ptr;
    shared_ptr<string> t2 = ptr;
    shared_ptr<string> t3 = ptr;
    shared_ptr<string> t4(ptr);//以上都是正确的添加了ref_count

    long refs = ptr.use_count();

    cout << *ptr << endl;
    cout << *h << endl;
    cout << refs << endl;
    return 0;
}
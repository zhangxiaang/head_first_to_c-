//
// Created by 张虾ang on 16/9/25.
//
#include <iostream>
#include <string>
#include <vector>
//#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

void push() {
    vector<int> container;
    int temp;
    while (cin >> temp) {
        container.push_back(temp);
    }
    cout << container.size() << endl;
}

int main() {
    vector<int> intCollection(10);//看来需要先定义容量才可以接着往里面填入数据 和[]一样
    cout << intCollection.size() << endl;
//    vector<int> hello(10, 10);
//    for (int i = 0; i < hello.size(); ++i) {
//        hello.push_back(i);//push_back是押入对象
//    }//通常的做法就是先定义一个空的容器 然后动态的压入元素
//    push();
    for (auto i:intCollection) {
        cout << i << endl;
    }
    for (auto &i:intCollection) {
        i = i + 4;
    }
    for (auto i:intCollection) {
        cout << i << endl;
    }
    return 0;
}
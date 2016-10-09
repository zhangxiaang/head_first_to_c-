//
// Created by 张虾ang on 16/10/8.
//


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main() {
    string val("Hello,World!");
    string val1("Hello,World2!");
    string val2("Hello,World3!");
    string val3("Hello,World4!");
    string val4("Hello,World5!");
    vector<string> v;
    v.push_back(val);
    v.push_back(val1);
    v.push_back(val2);
    v.push_back(val3);
    v.push_back(val4);

    auto it = v.begin();
    //it -> the baseAddr of header element
    cout << * it.base() << endl;
    return 0;
}
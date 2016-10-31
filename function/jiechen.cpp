//
// Created by 张虾ang on 16/10/27.
//

#include <iostream>
#include <vector>
#include "functionc.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    //put functions into the header file
    int result = jiechen(12);
    cout << result << endl;

    int adds = add(1, 2);
    cout << adds << endl;

    string s1 = "21312";
    string s2 = "123213123";
    bool res = compare(s1, s2);
    cout << res << endl;
    cout << s1 << endl;//可见传递引用的话是影响到了s1

    int counts = 0;

    int index = indexOfStringAndCounts(s1, '3', counts);
    cout << "first index:" << index << endl;
    cout << "total counts:" << counts << endl;
    return 1;
}
//
// Created by 张虾ang on 16/10/8.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main() {
    vector<string> container;
    string temp;
    while (cin >> temp) {
        for (char &c:temp) {
            c = toupper(c);
        }
        container.push_back(temp);
    }

    for (string s:container) {
        cout << s << endl;
    }

    vector<int> v1(10, 42);
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(42);
    }
    vector<int> v3;
    while (v3.size() < 10) {
        v3.push_back(42);
    }

    vector<int> strange;
    int tempint;
    while (cin >> tempint) {
        strange.push_back(tempint);
    }
    //output neightbor elements
    int sizes = strange.size();
    for (int j = 0; j < sizes - 1; ++j) {
        cout << strange[j] + strange[j + 1] << endl;
    }
    //Complementary
    for (int j = 0; j < sizes; ++j) {
        cout << strange[j] + strange[sizes - 1 - j] << endl;
    }
    return 0;
}

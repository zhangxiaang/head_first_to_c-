//
// Created by 张虾ang on 16/10/8.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
//    vector<std::string> v2;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(i);
    }
//    std::string word;
//    while (std::cin >> word) {
//        v2.push_back(word);
//    }

    for (int i:v2) {
        cout << i << endl;
    }

    for (int &i:v2) {
        i = i * i;//change the val of vector
    }

    for (int i:v2) {
        cout << i << endl;
    }

    v2[9] = 88;//change the val by index
    for (int i:v2) {
        cout << i << endl;
    }

    for (int i:v2) {
        i = 10;//just effect the copy val
    }
    for (int i:v2) {
        cout << i << endl;
    }

    vector<int> scores(11, 0);
    int grade;
    while (std::cin >> grade) {
        if (grade <= 100) {
            ++scores[grade / 10];//change the val of the 'index'
        }
    }
    return 0;
}
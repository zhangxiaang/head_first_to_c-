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

template<typename T>
T remove_if(T beg, T end) {
    T dest = beg;
    for (T itr = beg; itr != end; ++itr) {
        if (!isspace(*itr)) {
            *(dest++) = *itr;
        }
    }
    //dest 是清除了space后的pointer的指向
    return dest;
}

int main() {
    string val("Hello,World!");
    string val1("Hello,World2!");
    string val2("Hello,World3!");
    string val3("Hello,World4!");
    string val4("Hello,World5!");
    vector<string> v;//相当于string本身就是一个iter vector 是一个iter的容器
    v.push_back(val);
    v.push_back(val1);

    v.push_back(val2);
    v.push_back(val3);
    v.push_back(val4);

    for (int i = 0; i < 4; ++i) {
        v.push_back("hahah");
    }

    for (int j = 0; j < v.size(); ++j) {
        cout << v[j] << endl;

    }

    auto it = v.begin();//获取到的是string的一个iter
    cout << *it.base() << endl;

    for (auto item : *it) {
        cout << item << endl;
    }

    //快速清除string内部的指定字符
    string s("1 2 3 4 5a s dc");
    s.erase(remove_if(s.begin(), s.end()), s.end());//直接擦掉pointer后面的部分即可
    cout << s << endl;
    cout << s.length() << endl;//长度也修改过来了



    const int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> int_v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    //the best(fast) way to init vector
    for (int &temp : int_v) {
        temp *= temp;
    }

    for (int temp:int_v) {
        cout << temp << endl;
    }

    auto mid = v.begin() + v.size() / 2;
    cout << *mid << endl;
    auto j = v.end();
//    iterate
    for (auto i = v.begin(); i != j; ++i) {
        cout << *i << endl;
        cout << j - i << endl;//距离的输出
    }

    auto begin = int_v.begin();
    cout << *begin << endl;
    auto end = int_v.end();
    cout << *end << endl;
    auto middle = int_v.begin() + (end - begin) / 2;
    cout << *middle << endl;
    while (middle != end && *middle != 1600) {
        if (1600 > *middle) {
            begin = middle + 1;
        } else if (1600 < *middle) {
            end = middle;
        } else {
            break;
        }
        middle = begin + (end - begin) / 2;
    }
    return 0;
}
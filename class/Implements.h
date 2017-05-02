//
// Created by 张虾ang on 16/11/8.
//

#ifndef C_PRIMER_PLUS_IMPLEMENTS_H
#define C_PRIMER_PLUS_IMPLEMENTS_H

#include "Interface.h"
#include "Sales_data.h"

class Implements : Interface, Sales_data {
public:
    int add(int a, int b) {
        return a + b;
    }

public:
    int multi(int a, int b) {
        return a * b;
    }

};

#endif //C_PRIMER_PLUS_IMPLEMENTS_H
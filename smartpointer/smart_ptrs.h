//
// Created by 张虾ang on 16/10/7.
//

#ifndef C_PRIMER_PLUS_SMART_PTRS_H
#define C_PRIMER_PLUS_SMART_PTRS_H

template<typename T>
class smart_ptrs {
public:
    smart_ptrs(T *);

    smart_ptrs(smart_ptrs *);

    T *operator->();

    smart_ptrs &operator=(smart_ptrs &);

    ~smart_ptrs();

private:
    int *count;
    T *p;

};


#endif //C_PRIMER_PLUS_SMART_PTRS_H

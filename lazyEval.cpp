#include<iostream>
using namespace std;
struct matrix
{
	double values[100][100];
	double* operator[](int i) { return values[i]; }

};

struct matrix_add {
   mutable struct rowEntry{ 
       double operator [](int k){
           matrix_add* pthis=(matrix_add*)this;
           return (pthis->a)[_currentRow][k]+(pthis->b)[_currentRow][k];
        }
       void setRow(int v){_currentRow=v;}
   private:
       int _currentRow;
   } _rowEntry;
   matrix_add(matrix & a, matrix & b) : a(a), b(b) { }
   rowEntry& operator[](int i)const {
       _rowEntry.setRow(i); 
       return _rowEntry;
    }
private:
    matrix & a;
    matrix  & b;
};

matrix_add operator +(matrix & a, matrix & b) {
    return matrix_add(a, b);
}

int main ()
{
    matrix A,B;
    A[3][4]=101; 
    B[3][4]=102;
    matrix_add R=A+B;
    int result = R[3][4];
    //cout<<result<<endl;
    int *intP = NULL;
    double *doubleP= NULL;
    float *floatP = NULL;
    bool *booelanP = NULL;
    // char *charP = booelanP;
    // char *charP = NULL;
    intP++;
    doubleP++;
    floatP++;
    booelanP--;
    // float居然是4字节的  bool一个字节
    cout<<intP<<endl;
    cout<<doubleP<<endl;
    cout<<floatP<<endl;
    cout<<(&booelanP)<<endl;//0x0 - 1 --> 0xffffffffffffffff
    // cout<<charP<<endl;
    return 0;
    //指针的魅力在于内存调用的位置指针拨动即可找到正确的index下的value 而不需要根据index去find
}
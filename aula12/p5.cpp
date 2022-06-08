#include <iostream>
#include "Operation.h"
#include <math.h>

using namespace std;

class Sum:public Operation{
    public:
        Sum(int op1, int op2) : Operation(op1, op2){}
        int operation() const override {return get_op1() + get_op2();}
};

class Power:public Operation{
    public:
        Power(int op1, int op2) : Operation(op1, op2){}
        int operation() const override {return pow(get_op1(),get_op2());}
};

int main(){
    return 0;
}
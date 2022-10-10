#include "Calculator.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

#pragma region Constructors

#pragma endregion

#pragma region

void Calculator::BasicOp(double x, double y, char sign){
    double result = 0;
    switch(sign){
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            if(y == 0){
                cout << "Cannot Divide by 0" << endl;
                return;
            }

            result = x / y;
            break;
    }

    cout << x << " " << sign << " " << y << " = " << result << endl;
        
}

void Calculator::powerOfTwo(const double& x){
    cout << x << "^2" << " = " << pow(x,2);
}



#pragma endregion



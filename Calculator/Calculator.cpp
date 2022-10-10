#include "Calculator.h"
#include <iostream>
#include <math.h>
#include <string.h>

using std::cout;
using std::endl;
using std::string;
using std:: to_string;

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param sign 
 */
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

    // Create a string which hold the result
    string stringResult = to_string(x) + " " + sign + to_string(y) + " "
                                + " = " + to_string(result);

    // Add the string to the stack
    inputs.push(stringResult);

    cout << x << " " << sign << " " << y << " = " << result << endl;
        
}

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 */
void Calculator::exponential(const double& x, const double& y){
    double result = pow(x,y);

    string stringResult = to_string(x) + " ^ " + to_string(y) + " = " + to_string(result); 
    inputs.push(stringResult);
    
    cout << x << "^" << y << " = " << result << endl;
}

/**
 * @brief 
 * 
 */
void Calculator::PrintHistory(){
    if(inputs.empty()){
        return;
    }

    string input = inputs.top();

    inputs.pop();

    PrintHistory();

    cout << input << endl;

    inputs.push(input);
}




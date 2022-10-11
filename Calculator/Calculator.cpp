#include "Calculator.h"
#include <iostream>
#include <string.h>
#include <regex>

#define _USE_MATH_DEFINES
#include <math.h>

using std::cout;
using std::endl;
using std::string;
using std:: to_string;
using std::regex_match;

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

bool stringParse(const string& input, string& method, double& numberValue){
    std::regex alphabet("[A-Za-z]");
    std::regex integer("[0-9]");

    string numStr = "";

    for(unsigned int i = 0; i < input.length(); i++){
        string single = input.substr(i, 1);

        if(regex_match(single, alphabet)){
            method += single;
        }

        if(regex_match(single, integer)){
            numStr += single;
        }

        if(single == "(" || single == ")"){
            continue;
        }
    }

    // By changing to lower case, to accept also upper case
    std::transform(method.begin(), method.end(), method.begin(), ::tolower);
    cout << method << endl;


    if(method == "sin" || method == "cos" || method == "tan"){
        try
        {
            numberValue = std::stod(numStr);
            return true;
        }
        catch(const std::exception& e)
        {
            return false;
        }
    }

    return false;
}

void Calculator::SinCosTan(string input){
    string method = "";
    double numberValue = 0;

    bool inputValid = stringParse(input, method, numberValue);

    cout << inputValid << endl;

    if(inputValid){
        double rad = numberValue * M_PI / 180; // Find the radian
        double result = 0;

        if(method == "sin")
            result = sin(rad);
        else if(method == "cos")
            result = cos(rad);
        else if(method == "tan")
            result = tan(rad);

        string stringResult = input + " = " + to_string(result);
        inputs.push(stringResult);

        cout << input << " = " << result << endl;    
    }
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




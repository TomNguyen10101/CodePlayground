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
 * @param input 
 * @param num1 
 * @param num2 
 */
bool stringParsing(string& input, double& num1, double& num2, char& sign){

    // Remove all the spaces between the character
    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

    string value1 = "";
    string value2 = "";

    std::regex digit("[0-9]+");
    std::regex opPattern("[\\-\\+\\/\\*\\^]");

    for(unsigned int i = 0; i < input.length(); i++){
        string single = input.substr(i,1);

        if(regex_match(single, digit)){
            if(sign == '\0')
                value1 += input[i];
            else
                value2 += input[i];
        }

        if(regex_match(single, opPattern))
            sign =  input[i];
    }

    try
    {
        num1 = std::stod(value1);
        num2 = std::stod(value2);
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }

    return false;
}


/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param sign 
 */
void Calculator::BasicOp(string input){

    double num1 = 0, num2 = 0;
    char sign = '\0';
    bool isValid = stringParsing(input, num1, num2, sign);

    if(!isValid){
        cout << "Invalid Format" << endl;
        return;
    }

    double result = 0;
    switch(sign){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0){
                cout << "Cannot Divide by 0" << endl;
                return;
            }

            result = num1 / num2;
            break;
    }

    // Create a string which hold the result
    string stringResult = to_string(num1) + " " + sign + to_string(num2) + " "
                                + " = " + to_string(result);

    // Add the string to the stack
    inputs.push(stringResult);

    cout << num1 << " " << sign << " " << num2 << " = " << result << endl;
        
}

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 */
void Calculator::exponential(string input){
    double x = 0;
    double y = 0;
    char sign = '\0';
    bool isValid = stringParsing(input, x, y, sign);

    if(input.length() < 3 || sign != '^' || !isValid){
        cout << "Invalid Format" << endl;
    }

    double result = pow(x,y);

    string stringResult = to_string(x) + " ^ " + to_string(y) + " = " + to_string(result); 
    inputs.push(stringResult);
    
    cout << x << "^" << y << " = " << result << endl;
}

/**
 * @brief This function is for parsing and validating input for 
 * sin cos tan function.
 * 
 * @param input 
 * @param method 
 * @param numberValue 
 * @return true 
 * @return false 
 */
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




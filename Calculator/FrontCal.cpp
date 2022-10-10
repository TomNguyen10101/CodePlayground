#include <iostream>
#include "Calculator.h"
#include <algorithm>
#include <cstring>
#include <limits>
#include <ios>

using std::cout;
using std::endl;
using std::cin;
using std::string;


/**
 * @brief 
 * 
 */
int menu(){
    cout << "  ####################################" << endl;
    cout << "  ######## DIGITAL CALCULATOR ########" << endl;
    cout << "  ####################################" << endl;

    cout << "1. Basic Operators " << endl;
    cout << "2. More Advanced Math" << endl;
    cout << "3. History" << endl;
    cout << "4. Exit" << endl; 

    cout << "Choose your option (1-4): ";
    
    int option;
    cin >> option;

    return option;
}

void stringParsing(string& input, double& num1, double& num2){

    // Remove all the spaces between the character
    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

    char* charArr = &input[0];

    try
    {
        string x;
        x.append(1, charArr[0]);
        num1 = std::stod(x);

        string y;
        y.append(1, charArr[2]);
        num2 = std::stod(y);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid Input" << '\n';
    }

}

/**
 * @brief 
 * 
 * @param cal 
 */
void option1(Calculator& cal){
    //Introduction line
    cout << "\n ############ Basic Operators ############" << endl;

    // Getting the input from the user
    string input = "";
    getline(cin, input);

    double num1 = 0;
    double num2 = 0;

    stringParsing(input, num1, num2);

    cal.BasicOp(num1, num2, input[1]);

    system("Pause");
}

/**
 * @brief 
 * 
 * @param cal 
 */
void option2(Calculator& cal){
    cout << "\n ############ More Advanced Math ############" << endl;
    cout << "1. sin(x), cos(x), tan(x), cotan(x)" << endl;
    cout << "2. x^y (x to the power of y)" << endl;

    int option;
    cin >> option;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string input = "";
    double x, y;

    switch(option){
        case 1:
            break;
        case 2:
            cout << "Enter the operation: ";
            getline(cin, input);
            stringParsing(input, x, y);

            if(input.length() < 3 || input[1] != '^'){
                cout << "Invalid Format" << endl;
            }

            cal.exponential(x,y);
            break;
    }

    system("Pause");

}


/**
 * @brief 
 * 
 * @param cal 
 */
void option3(Calculator& cal){
    cout << "\n ############ History ############" << endl;
    cal.PrintHistory();
    system("Pause");
}


int main(int argc, char** argv){
    int option = 0;   
    Calculator calculator;

    while((option = menu()) != 4){
        // clear buffer before taking new line
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(option){
            case 1:
                option1(calculator);
                break;
            case 2:
                option2(calculator);
                break;
            case 3:
                option3(calculator);
                break;
        }

        system("CLS");
    } 
    
    cout << "Goodbye!!!" << endl;

    system("Pause");
    return 0;
}

#include <iostream>
#include "Calculator.h"
#include <cstring>
#include <limits>
#include <ios>
#include <regex>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::regex_match;


/**
 * @brief This function will display the menu
 * 
 */
int menu(){
    cout << "  ####################################" << endl;
    cout << "  ######## DIGITAL CALCULATOR ########" << endl;
    cout << "  ####################################" << endl;

    cout << "  #########################" << endl;
    cout << "  1. Basic Operators " << endl;
    cout << "  2. More Advanced Math" << endl;
    cout << "  3. History" << endl;
    cout << "  4. Exit" << endl; 
    cout << "  #########################" << endl;

    cout << "  Choose your option (1-4): ";
    
    int option;
    cin >> option;

    return option;
}

/**
 * @brief This function will take in the input from the user
 * and call the BasicOp function to calculate and print out
 * the result. 
 * 
 * @param cal 
 */
void option1(Calculator& cal){
    //Introduction line
    cout << "\n  ############ Basic Operators ############" << endl;

    // Getting the input from the user
    string input = "";
    getline(cin, input);

    cal.BasicOp(input);

    system("Pause");
}

/**
 * @brief This function will take in the input from the user
 * and call the function based on the choosing option to calculate and print out
 * the result. 
 * 
 * @param cal 
 */
void option2(Calculator& cal){
    cout << "\n  ############ More Advanced Math ############" << endl;
    cout << "  1. sin(x), cos(x), tan(x), cotan(x)" << endl;
    cout << "  2. x^y (x to the power of y)" << endl;

    int option;
    cout << " Choose your option: ";
    cin >> option;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string input = "";

    switch(option){
        case 1:
            cout << "Enter the operation: ";
            getline(cin, input);
            cal.SinCosTan(input);
            break;
        case 2:
            cout << "Enter the operation: ";
            getline(cin, input);
            cal.exponential(input);
            break;
    }

    system("Pause");
}


/**
 * @brief This function is used for printing out a list
 * of past input's result
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
    
    cout << "\nGoodbye!!!" << endl;

    system("Pause");
    return 0;
}

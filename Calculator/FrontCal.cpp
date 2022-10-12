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
 * @brief 
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
    char sign = '\0';

    // Checking if the input is valid
    bool isValid = stringParsing(input, num1, num2, sign);

    if(!isValid)
        cout << "Invalid Format" << endl;
    else
        cal.BasicOp(num1, num2, sign);

    system("Pause");
}

/**
 * @brief 
 * 
 * @param cal 
 */
void option2(Calculator& cal){
    cout << "\n ############ More Advanced Math ############" << endl;
    cout << " 1. sin(x), cos(x), tan(x), cotan(x)" << endl;
    cout << " 2. x^y (x to the power of y)" << endl;

    int option;
    cout << " Choose your option: ";
    cin >> option;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string input = "";
    double x, y;
    char sign = '\0';

    switch(option){
        case 1:
            getline(cin, input);
            cal.SinCosTan(input);
            break;
        case 2:
            cout << "Enter the operation: ";
            getline(cin, input);
            bool isValid = stringParsing(input, x, y, sign);

            if(input.length() < 3 || sign != '^' || !isValid){
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
    
    cout << "\nGoodbye!!!" << endl;

    system("Pause");
    return 0;
}

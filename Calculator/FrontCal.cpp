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

    // Remove all the spaces between the character
    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

    char* charArr = &input[0];

    try
    {
        string x;
        x.append(1, charArr[0]);
        double num1 = std::stod(x);

        string y;
        y.append(1, charArr[2]);
        double num2 = std::stod(y);

        cal.BasicOp(num1, num2, charArr[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid Input" << '\n';
    }
    
    system("Pause");
}


/**
 * @brief 
 * 
 */
void option3(Calculator& cal){
    cout << "\n ############ History ############" << endl;
    cal.printHistory();
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

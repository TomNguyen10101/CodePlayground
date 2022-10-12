#ifndef CALCULATOR
#define CALCULATOR

#include <iostream>
#include <stack>

class Calculator{
    private:
        std::stack<std::string> inputs;
        
    public:
        void BasicOp(std::string input);
        void exponential(std::string input);
        void PrintHistory();
        void SinCosTan(std::string input);
};
#endif

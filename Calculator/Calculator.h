#ifndef CALCULATOR
#define CALCULATOR

#include <iostream>
#include <stack>

class Calculator{
    private:
        std::stack<std::string> inputs;
        
    public:
        void BasicOp(double x, double y, char sign);
        void exponential(const double& x, const double& power);
        void PrintHistory();
        void SinCosTan(std::string input);
};
#endif

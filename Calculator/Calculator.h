#ifndef CALCULATOR
#define CALCULATOR

#include <iostream>
#include <stack>

class Calculator{
    private:
        std::stack<std::string> inputs;
        
    public:
        // Functions
        void BasicOp(double x, double y, char sign);
        void powerOfTwo(const double& x);
        void exponential(const double& x, const double& power);
        void printHistory();
};
#endif

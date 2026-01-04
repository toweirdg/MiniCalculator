#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

// Calculator acts as a high-level interface for evaluating expressions.
// It delegates parsing and evaluation to the Parser class.
class Calculator {
public:
    // Evaluates a mathematical expression given as a string
    double evaluate(const std::string& expression);
};

#endif

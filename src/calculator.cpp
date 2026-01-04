#include "calculator.h"
#include "parser.h"

// Evaluates a mathematical expression provided as a string.
// This class delegates the actual parsing logic to the Parser
// to keep responsibilities separated.
double Calculator::evaluate(const std::string& expression) {
    Parser parser(expression);

    // Let the parser handle operator precedence and expression evaluation
    return parser.parseExpression();
}

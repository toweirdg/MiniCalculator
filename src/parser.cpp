#include "parser.h"
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

// Initialize parser with expression and starting position
Parser::Parser(const string& expr) : expr(expr), pos(0) {}


// Handles addition and subtraction
double Parser::parseExpression() {
    double result = parseTerm();

    while (true) {
        skipWhitespace();

        if (peek() == '+') {
            get();
            result += parseTerm();
        } else if (peek() == '-') {
            get();
            result -= parseTerm();
        } else {
            break;
        }
    }

    return result;
}


// Handles multiplication, division, and modulo
double Parser::parseTerm() {
    double result = parseFactor();

    while (true) {
        skipWhitespace();

        if (peek() == '*') {
            get();
            result *= parseFactor();
        } else if (peek() == '/') {
            get();
            double divisor = parseFactor();

            if (divisor == 0) {
                throw runtime_error("Division by zero");
            }

            result /= divisor;
        } else if (peek() == '%') {
            get();

            int left = static_cast<int>(result);
            int right = static_cast<int>(parseFactor());

            if (right == 0) {
                throw runtime_error("Modulo by zero");
            }

            result = left % right;
        } else {
            break;
        }
    }

    return result;
}


// Handles exponentiation (right-associative)
double Parser::parseFactor() {
    double base = parsePrimary();
    skipWhitespace();

    if (peek() == '^') {
        get();
        double exponent = parseFactor(); // recursion ensures correct precedence
        return pow(base, exponent);
    }

    return base;
}


// Parses numbers and parenthesized expressions
double Parser::parsePrimary() {
    skipWhitespace();

    // Handle parentheses
    if (peek() == '(') {
        get(); // consume '('
        double value = parseExpression();

        if (get() != ')') {
            throw runtime_error("Missing closing parenthesis");
        }

        return value;
    }

    // Parse numeric value (with optional unary sign)
    size_t start = pos;

    if (peek() == '-' || peek() == '+') {
        get(); // unary sign
    }

    while (isdigit(peek()) || peek() == '.') {
        get();
    }

    string numberStr = expr.substr(start, pos - start);

    try {
        return stod(numberStr);
    } catch (...) {
        throw runtime_error("Invalid number: " + numberStr);
    }
}


// Skips whitespace between tokens
void Parser::skipWhitespace() {
    while (isspace(peek())) {
        get();
    }
}


// Look at current character without consuming it
char Parser::peek() const {
    return pos < expr.length() ? expr[pos] : '\0';
}


// Consume and return current character
char Parser::get() {
    return pos < expr.length() ? expr[pos++] : '\0';
}

#ifndef PARSER_H
#define PARSER_H

#include <string>

// Parser class implements a simple recursive descent parser
// to evaluate mathematical expressions with correct precedence.
class Parser {
public:
    // Construct parser with the input expression
    explicit Parser(const std::string& expr);

    // Entry point for parsing and evaluating the expression
    double parseExpression();

private:
    std::string expr; // Full expression string
    size_t pos;       // Current parsing position

    // Parsing methods for different precedence levels
    double parseTerm();       // Handles *, /, %
    double parseFactor();     // Handles ^
    double parsePrimary();    // Handles numbers and parentheses

    // Utility helpers
    void skipWhitespace();
    char peek() const;        // Look at current character
    char get();               // Consume current character
};

#endif

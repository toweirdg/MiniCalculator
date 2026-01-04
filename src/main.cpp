#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

int main() {
    Calculator calculator;
    string userInput;

    cout << "Mini Calculator\n";
    cout << "Type 'exit' to quit\n\n";

    // Main input loop
    while (true) {
        cout << "> ";
        getline(cin, userInput);

        // Exit condition
        if (userInput == "exit") {
            break;
        }

        // Ignore empty input lines
        if (userInput.empty()) {
            continue;
        }

        try {
            // Evaluate the expression entered by the user
            double result = calculator.evaluate(userInput);
            cout << "Result: " << result << "\n";
        } catch (const exception& ex) {
            // Catch and display errors from invalid expressions
            cout << "Error: " << ex.what() << "\n";
        }
    }

    return 0;
}

#include "MathParser.h"

Stack<double> MathParser::operands;
Stack<char> MathParser::operators;

bool MathParser::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int MathParser::priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

double MathParser::applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

void MathParser::evaluate() {
    double  val2 = operands.top()   ; operands.pop();
    double  val1 = operands.top()   ; operands.pop();
    char    op   = operators.top()  ; operators.pop();

    operands.push(applyOperator(val1, val2, op));
}

double MathParser::parse(const std::string& expression) {
    for (int i = 0; i < expression.size(); ++i) {
        switch (char currentChar = expression[i]) {
            case ' ':
                continue;

            case '(':
                operators.push(currentChar);
                break;

            case ')':
                // Start evaluating until we find '('
                while (!operators.empty() && operators.top() != '(')
                    evaluate();

                operators.pop(); // pop '('
                break;

            default:
                if (isdigit(currentChar)) {
                    double value = 0;

                    while (i < expression.size() && isdigit(expression[i]))
                        value = (value * 10) + (expression[i++] - '0');

                    operands.push(value);
                    --i; // rewind one character to avoid skipping an operator or a parenthesis
                }

                if (isOperator(currentChar)) {
                    // start evaluating in case the current operator has lower priority than the top operator, ex: (5 * 3 + 2) -> (15 + 2)
                    while (
                        !operators.empty()
                        && priority(operators.top()) >= priority(currentChar)
                    ) evaluate();

                    operators.push(currentChar);
                }

                break;
        }
    }

    while (!operators.empty()) evaluate();
    return operands.top();
}
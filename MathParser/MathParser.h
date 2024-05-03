#pragma once
#include <string>
#include "Stack.h"

class MathParser {
    static Stack<double> operands;
    static Stack<char>  operators;

    static bool isOperator(char c);
    static int priority(char op);
    static double applyOperator(double a, double b, char op);
    static void evaluate();

public:
    static double parse(const std::string& expression);
};
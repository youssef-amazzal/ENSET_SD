#include <iostream>

#include "MathParser.h"

int main() {
    // For now, this works with positive integers only
    std::cout << MathParser::parse("(10 * 3 + (2)) * 2") << std::endl;
    return 0;
}

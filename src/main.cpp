#include <iostream>
#include "type.h"

import Math;

int main() {
    std::cout << "sum - " << sum_left_fold(1, -2, 3, -4, 5) << std::endl;

    int a = 1;
    const int& c = 1;
    std::cout << getTypeString(c) << std::endl;
    return 0;
}
#include <iostream>
#include "c_helper.cpp"

void cfunction () {
    if (cHelperFunction () == 3) {
        std::cout << "cHelperFunction  called" << std::endl;
    }
    std::cout << "cfunction  called" << std::endl;
}

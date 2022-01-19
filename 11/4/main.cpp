#include <iostream>


float getFloat(std::string value) {

    int i;
    int dots = 0;
    std::string stringLeft;
    std::string stringRight;
    int intLeft;
    float floatRight;
    float result;


    for (i = 0; i < value.length(); i++) {

        if ((value[i] == '.') || ((value[i] == NULL) && (dots == 0))) {
            dots++;
            if (dots == 1) {
                i++;
                break;
            }
        }
        stringLeft += value[i];
    }

    if (dots != 0) {
        for (i; i < value.length(); i++) {
            stringRight += value[i];
        }
    } else {
        stringRight = "";
    }

    intLeft = std::stoi(stringLeft);

    if (stringRight != "") {
        floatRight = std::stoi(stringRight);
        for (int j = 0; j < stringRight.length(); j++) {
            floatRight *= 0.1;
        }
    } else {
        floatRight = 0.0;
    }


    if (intLeft >= 0) {
        result = (float) intLeft + floatRight;
    } else {
        result = (float) intLeft - floatRight;
    }

    return result ;


}

void compare(std::string stringOne, std::string stringTwo) {
    float floatOne = getFloat(stringOne);
    float floatTwo = getFloat(stringTwo);


    if (floatOne < floatTwo) {
        std::cout << "Less" << std::endl;
    } else if (floatOne == floatTwo) {
        std::cout << "Equal" << std::endl;
    } else {
        std::cout << "More" << std::endl;
    }


}

int main() {
    std::string stringOne;
    std::string stringTwo;
    float numberOne;
    float numberTwo;

    std::cout << "Enter the first number: " << std::endl;
    std::cin >> stringOne;
    std::cout << "Enter the second number: " << std::endl;
    std::cin >> stringTwo;

    //  numberOne = getFloat (stringOne);
    //  numberTwo = getFloat (stringTwo);

    //  std::cout << numberOne << " " << numberTwo << std::endl;

    compare(stringOne, stringTwo);


}

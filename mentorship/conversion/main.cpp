#include <iostream>

void decimalToBinary(int a) {

    if (a) {
        decimalToBinary(a >> 1);
        std::cout << (a & 1);
    }

}

void decimalToAny(int a, int target) {
    if (a) {
        decimalToAny (a/target, target);
        std::cout << (a%target);
    }

}

int toDecimal(int a, int initial) {
    int base = 1;
    int result = 0;
    int temp = a;
    int lastDigit;

    while (temp) {
        lastDigit = temp % 10;
        temp /= 10;

        result += lastDigit * base;

        base *= initial;
    }



return result;
}

void convert(int a, int initial, int target) {


    if ((initial == 10) && (target == 2)) {
        decimalToBinary(a);

    } else if (target == 10) {
      std::cout << toDecimal(a, initial);

    } else if (initial == 10) {
       decimalToAny(a, target);


    } else if ((target >0 && target <10) && (initial > 0 && initial <10)) {
       decimalToAny((toDecimal(a, initial)), target);
    }

    else {
        std::cout << "Wrong systems, try again.";
    }

    std::cout << std::endl;
}



int main() {
    int a;
    int initial;
    int target;

    while (true) {
        std::cout << "Enter a number" << std::endl;
        std::cin >> a;

        if (a == 0) {
            break;
        }

        std::cout << "Enter initial numeric system" << std::endl;
        std::cin >> initial;
        std::cout << "Enter target numeric system" << std::endl;
        std::cin >> target;
        convert(a, initial, target);


    }

}
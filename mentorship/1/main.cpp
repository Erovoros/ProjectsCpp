#include <iostream>
#include <cmath>

std::string decimalToBinary(std::string value) {
    int decimal = std::stoi(value);
    std::string result;

    for (int i = 1; i <= decimal; i *= 2) {
        result += '0';


    }
    for (int i = 0; decimal > 0; i++) {
        if (decimal >= pow(2, result.length() - i - 1)) {
            decimal -= pow(2, result.length() - i - 1);
            result[i] = '1';
        }
    }
    return result;
}


std::string convert(std::string value, int current, int target) {
    std::string result = decimalToBinary(value);

    return result;

}


int main() {
    std::string value;
    std::string result;
    int current;
    int target;

    std::string binary;
    std::string decimal;
    std::string hex;

    while (true) {
        std::cout << "Enter a value: " << std::endl;
        std::cin >> value;

        if (value == "0") {
            break;
        }

        std::cout << "Enter current numeric system: " << std::endl;
        std::cin >> current;

        std::cout << "Enter target numeric system: " << std::endl;
        std::cin >> target;

        result = convert(value, current, target);

        std::cout << result << std::endl;
    }


}

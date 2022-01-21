#include <iostream>

std::string encrypt_caesar(std::string caesar, int number) {


    for (int i = 0; i < caesar.length(); i++) {
        if ((((caesar[i] >= 97) && (caesar[i] <= 122)) && ((caesar[i] + number) <= 122)) &&
            ((caesar[i] + number) >= 97) ||
            (((caesar[i] >= 65) && (caesar[i] <= 90)) && ((caesar[i] + number) <= 90)) &&
            ((caesar[i] + number) >= 65)) {

            caesar[i] += number;
        } else if (((caesar[i] >= 97) && (caesar[i] <= 122)) && (((caesar[i] + number) >= 97)) &&
                   (((caesar[i] + number) > 122))) {

            caesar[i] = 'a' + (caesar[i] + (number - 122) - 1);
        } else if (((caesar[i] >= 97) && (caesar[i] <= 122)) && ((caesar[i] + number) < 97)) {

            caesar[i] = 'z' - ((abs(number) - (caesar[i] - 97))) + 1;
        } else if (((caesar[i] >= 65) && (caesar[i] <= 90)) && ((caesar[i] + number) >= 65) &&
                   ((caesar[i] + number) > 90)) {
            caesar[i] = 'A' + (caesar[i] + (number - 90) - 1);
        } else if (((caesar[i] >= 65) && (caesar[i] <= 90)) && ((caesar[i] + number) < 65)) {
            caesar[i] = 'Z' - ((abs(number) - (caesar[i] - 65))) + 1;
        }


    }

    return caesar;

}

std::string decrypt_caesar(std::string caesar, int number) {

    caesar = encrypt_caesar(caesar, -number);

    return caesar;


}

int main() {
    std::string caesar;
    int number;

    std::cout << "Enter a string to convert: " << std::endl;
    std::getline(std::cin, caesar);
    std::cout << "Enter a number for shift: " << std::endl;
    std::cin >> number;

    number = number%26;


    caesar = encrypt_caesar(caesar, number);

    std::cout << caesar << std::endl;

    caesar = decrypt_caesar(caesar, number);

    std::cout << caesar << std::endl;


}

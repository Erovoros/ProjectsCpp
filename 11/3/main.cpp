#include <iostream>


int getNumber(std::string ip, int number) {
    std::string extractNumber;
    int result;
    int dots = 0;
    int i;
    int dictCounter = 0;
    std::string extractDictionary = "0123456789";

    for (i = 0; i < ip.length(); i++) {
        if (number == 1) {
            i = 0;
            break;
        }

        if ((ip[i] == '.') || (ip[i] == NULL)) {
            dots++;
            if (dots == number - 1) {
                i++;
                break;
            }
        }

    }

    {
        for (i; ((ip[i] != '.') && (ip[i] != NULL)); i++) {
            extractNumber += ip[i];

        }
    }

    if ((extractNumber[0] == NULL) || ((extractNumber[0] == 48) && (extractNumber[1] != NULL)) ) {
        return -1;
    }

    for (int i = 0; i < extractNumber.length(); i++) {
        for (int j = 0; j < extractDictionary.length(); j++) {
            if (extractNumber[i] == extractDictionary[j]) {
                dictCounter++;
                break;
            }
        }
        if (dictCounter == 0) {
            return -1;
        }
    }
    result = std::stoi(extractNumber);
    return result;
}


bool is_number_correct(int number) {

    ((number > 255) || (number < 0)) ? false : true;


}

bool is_correct(std::string ip) {
    int dotCounter = 0;
    int letterCounter;
    std::string dictionary = "0123456789.";

    int numberOne = getNumber(ip, 1);
    int numberTwo = getNumber(ip, 2);
    int numberThree = getNumber(ip, 3);
    int numberFour = getNumber(ip, 4);

    for (int i = 0; i < ip.length(); i++) {
        letterCounter = 0;
        for (int j = 0; j < dictionary.length(); j++) {
            if (ip[i] == dictionary[j]) {
                letterCounter++;
                break;
            }

        }
        if (letterCounter == 0) {
            std::cout << "Wrong symbols in the address" << std::endl;
            return false;
        }

        if (ip[i] == '.') {
            dotCounter++;
        }

        if ((ip[i] == '.') && (ip[i + i] == '.')) {
            std::cout << "Two dots in a row" << std::endl;
            return false;
        }
    }


    if (ip[ip.length() - 1] == '.') {
        std::cout << "A dot can't be in the end of the string" << std::endl;
        return false;
    }


    if (dotCounter != 3) {
        std::cout << "Wrong number" << std::endl;
        return false;
    }


    if ((is_number_correct(numberOne)) && (is_number_correct(numberTwo)) && (is_number_correct(numberThree)) &&
        (is_number_correct(numberFour))) {

        return true;
    } else {
        return false;
    }
}


int main() {

    std::string ip;


    std::cout << "Enter an IP address:" << std::endl;
    std::cin >> ip;
    (is_correct(ip)) ? (std::cout << "Yes" << std::endl) : (std::cout << "No" << std::endl);


}

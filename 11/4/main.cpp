#include <iostream>

bool checkForZero (std::string stringOne, std::string stringTwo) {
    std::string dictionary = "-0.";
    bool stringOneZero;
    bool stringTwoZero;
    int counterOne = 0;
    int counterTwo = 0;
    for (int i = 0; i < stringOne.length(); i++) {
        for (int j = 0; j < dictionary.length(); j++) {
            if (stringOne[i] == dictionary[j]) {
                counterOne++;
                break;
            }
        }
    }
    if (counterOne == stringOne.length()) {
        stringOneZero = true;
    }

    for (int i = 0; i < stringTwo.length(); i++) {
        for (int j = 0; j < dictionary.length(); j++) {
            if (stringTwo[i] == dictionary[j]) {
                counterTwo++;
                break;
            }
        }
    }
    if (counterTwo == stringTwo.length()) {
        stringTwoZero = true;
    }

    if (stringOneZero && stringTwoZero) {
        return true;
    } else {
        return false;
    }
}

std::string getLeftString(std::string fullString) {

    int i;
    int dots = 0;
    std::string stringLeftBeta;
    std::string stringLeft;
    int index;


    for (i = 0; i < fullString.length(); i++) {


        if ((fullString[i] == '.') || ((fullString[i] == NULL) && (dots == 0))) {
            dots++;
            if (dots == 1) {
                i++;
                break;
            }
        }
        stringLeftBeta += fullString[i];
    }

    for (index = 0; index < stringLeftBeta.length(); index++) {
        if (stringLeftBeta[index] != '0') {
            break;
        }


    }

    for (index; index < stringLeftBeta.length(); index++) {
        stringLeft += stringLeftBeta[index];
    }

    return stringLeft;


}

std::string getRightString(std::string fullString, std::string leftString) {
    std::string rightString;

    int counterZero;

    for (counterZero = 0; counterZero < fullString.length(); counterZero++) {
        if (fullString[counterZero] != '0') {
            break;
        }
    }


    if (fullString.length() == leftString.length()) {
        rightString += '0';
    }

    for (int i = leftString.length() + counterZero + 1; i < fullString.length(); i++) {
        rightString += fullString[i];
    }
    return rightString;
}


int compareLeftStrings(std::string stringOne, std::string stringTwo) {

    char intOne;
    char intTwo;

    if ((stringOne[0] == '-') && (stringTwo[0] != '-')) {
        return -1;
    } else if ((stringOne[0] != '-') && (stringTwo[0] == '-')) {
        return 1;
    } else if (stringOne.length() < stringTwo.length()) {
        for (int i = stringOne.length(); i < stringTwo.length(); i++) {
            stringOne += '0';
        }
    } else if (stringOne.length() > stringTwo.length()) {
        for (int i = stringTwo.length(); i < stringOne.length(); i++) {
            stringTwo += '0';
        }
    }

    for (int i = 0; i < stringOne.length(); i++) {
        if (stringOne[i] != stringTwo[i]) {
            intOne = stringOne[i];
            intTwo = stringTwo[i];
            break;
        }
    }

    if ((stringOne[0] != '-') && (stringTwo[0] != '-')) {
        if (intOne > intTwo) {
            return 1;
        } else if (intOne < intTwo) {
            return -1;
        }
    }

    if ((stringOne[0] == '-') && (stringTwo[0] == '-')) {
        if (intOne < intTwo) {
            return 1;
        } else if (intOne > intTwo) {
            return -1;
        }
    }
    return 0;
}

char getSign(std::string stringOne, std::string stringTwo) {
    if ((stringOne[0] == '-') && (stringTwo[0] == '-')) {
        return '-';
    } else if ((stringOne[0] != '-') && (stringTwo[0] != '-')) {
        return '+';
    }
}

int compareRightStrings(std::string stringOne, std::string stringTwo, char sign) {

    char floatOne;
    char floatTwo;




    if (stringOne.length() < stringTwo.length()) {
        for (int i = stringOne.length(); i < stringTwo.length(); i++) {
            stringOne += '0';
        }
    } else if (stringOne.length() > stringTwo.length()) {
        for (int i = stringTwo.length(); i < stringOne.length(); i++) {
            stringTwo += '0';
        }
    }

    for (int i = 0; i < stringOne.length(); i++) {
        if (stringOne[i] != stringTwo[i]) {
            floatOne = stringOne[i];
            floatTwo = stringTwo[i];
            break;
        }
    }

    if (sign != '-') {
        if (floatOne > floatTwo) {
            return 1;
        } else if (floatOne < floatTwo) {
            return -1;
        }
    }

    if (sign == '-') {
        if (floatOne < floatTwo) {
            return 1;
        } else if (floatOne > floatTwo) {
            return -1;
        }
    }
    return 0;
}

void finalCompare(int firstResult, int secondResult) {


    if (firstResult == 1) {
        std::cout << "More";
    } else if (firstResult == -1) {
        std::cout << "Less";
    } else if ((firstResult == 0) && (secondResult == 0)) {
        std::cout << "Equal";
    } else if ((firstResult == 0) && (secondResult == -1)) {
        std::cout << "Less";
    } else if ((firstResult == 0) && (secondResult == 1)) {
        std::cout << "More";
    }
}


int main() {
    std::string stringOne;
    std::string stringTwo;


    std::cout << "Enter the first number: " << std::endl;
    std::cin >> stringOne;
    std::cout << "Enter the second number: " << std::endl;
    std::cin >> stringTwo;


    std::string firstLeftString;
    std::string secondLeftString;

    std::string firstRightString;
    std::string secondRightString;

    int result1;
    int result2;
    char sign;

    if (checkForZero(stringOne, stringTwo)) {
    std::cout << "Equal";
    return 0;
}
    firstLeftString = getLeftString(stringOne);
    secondLeftString = getLeftString(stringTwo);
    firstRightString = getRightString(stringOne, firstLeftString);
    secondRightString = getRightString(stringTwo, secondLeftString);

    sign = getSign(stringOne, stringTwo);

    result1 = compareLeftStrings(firstLeftString, secondLeftString);
    result2 = compareRightStrings(firstRightString, secondRightString, sign);

    finalCompare(result1, result2);


}

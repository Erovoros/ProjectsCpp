#include <iostream>


bool checkString(std::string firstString) {
    std::string dictionary = "XO.";
    int checkDictionary;

    if (firstString.length() != 3) {
        std::cout << "A string should be 3 symbols long" << std::endl;
        return false;
    }

    for (int i = 0; i < firstString.length(); i++) {
        checkDictionary = 0;
        for (int j = 0; j < dictionary.length(); j++) {
            if (firstString[i] == dictionary[j]) {
                checkDictionary++;
                break;
            }
        }
        if (checkDictionary == 0) {
            std::cout << "Wrong string" << std::endl;
            return false;
        }


    }
    return true;


}

char getElement(int xpos, int ypos, std::string firstString, std::string secondString, std::string thirdString) {


    if ((xpos == 1) && (ypos == 1)) {
        return firstString[0];
    } else if
            ((xpos == 2) && (ypos == 1)) {
        return firstString[1];
    } else if
            ((xpos == 3) && (ypos == 1)) {
        return firstString[2];
    } else if
            ((xpos == 1) && (ypos == 2)) {
        return secondString[0];
    } else if
            ((xpos == 2) && (ypos == 2)) {
        return secondString[1];
    } else if
            ((xpos == 3) && (ypos == 2)) {
        return secondString[2];
    } else if
            ((xpos == 1) && (ypos == 3)) {
        return thirdString[0];
    } else if
            ((xpos == 2) && (ypos == 3)) {
        return thirdString[1];
    } else if
            ((xpos == 3) && (ypos == 3)) {
        return thirdString[2];
    }

}

bool check (char element1, char element2, char element3, char xo) {
    if ((element1 == xo) && (element2 == xo) && (element3 == xo)) {
        return true;
    } else {
        return false;
    }

}


char checkWinningLine(std::string firstString, std::string secondString, std::string thirdString) {
    char element1 = getElement(1, 1, firstString, secondString, thirdString);
    char element2 = getElement(2, 1, firstString, secondString, thirdString);
    char element3 = getElement(3, 1, firstString, secondString, thirdString);
    char element4 = getElement(1, 2, firstString, secondString, thirdString);
    char element5 = getElement(2, 2, firstString, secondString, thirdString);
    char element6 = getElement(3, 2, firstString, secondString, thirdString);
    char element7 = getElement(1, 3, firstString, secondString, thirdString);
    char element8 = getElement(2, 3, firstString, secondString, thirdString);
    char element9 = getElement(3, 3, firstString, secondString, thirdString);

    if (check (element1, element2, element3, 'X') || (check(element4, element5, element6, 'X')) ||
        (check(element7, element8, element9, 'X')) ||
        (check(element1, element4, element7, 'X')) || (check(element2, element5, element8, 'X')) ||
        (check(element3, element6, element9, 'X')) ||
        (check(element1, element5, element9, 'X')) || (check(element3, element5, element7, 'X'))) {
        return 'X';
    } else if (check (element1, element2, element3, 'O') || (check(element4, element5, element6, 'O')) ||
               (check(element7, element8, element9, 'O')) ||
               (check(element1, element4, element7, 'O')) || (check(element2, element5, element8, 'O')) ||
               (check(element3, element6, element9, 'O')) ||
               (check(element1, element5, element9, 'O')) || (check(element3, element5, element7, 'O'))) {

        return 'O';
    } else {
        return NULL;
    }
}


void checkField(std::string firstString, std::string secondString, std::string thirdString) {

    int oCounter = 0;
    int xCounter = 0;
    char winner;

    std::string fullString = firstString + secondString + thirdString;

    for (int i = 0; i < fullString.length(); i++) {
        if (fullString[i] == 'O') {
            oCounter++;
        } else if (fullString[i] == 'X') {
            xCounter++;
        }
    }

    winner = (checkWinningLine(firstString, secondString, thirdString));

    if (!(checkString(firstString)) || !(checkString(secondString)) || !(checkString(thirdString))) {
        std::cout << "Incorrect";
    } else if (oCounter > xCounter) {
        std::cout << "Incorrect";
    } else if (winner == NULL) {
        std::cout << "Nobody";
    } else if ((winner == 'X') && (oCounter >= xCounter)) {
        std::cout << "Incorrect";;
    } else if ((winner == 'O') && (xCounter >= 4)) {
        std::cout << "Incorrect";
    } else if (winner == 'X') {
        std::cout << "Petya Won";
    } else if (winner == 'O') {
        std::cout << "Vanya won";
    }


}

int main() {
    std::string firstString;
    std::string secondString;
    std::string thirdString;

    std::cout << "Enter three strings:" << std::endl;
    std::cin >> firstString >> secondString >> thirdString;

    checkField(firstString, secondString, thirdString);


}

#include <iostream>


std::string leftString(std::string email) {

    std::string leftString;

    for (int i = 0; email[i] != '@'; i++) {
        leftString += email[i];
    }
    return leftString;

}

std::string rightString(std::string email, std::string leftString) {
    std::string rightString;
    int j = 0;
    for (int i = leftString.length() + 1; email[i] != NULL; i++, j++) {

        rightString += email[i];
    }

    return rightString;

}

bool is_LeftString(std::string leftString) {
    std::string dictionaryLeft = "ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghigklmnopqrstuvwxyz0123456789-.!#$%&'*+-/=?^_`{|}~";
    int leftDictCounter;


    if ((leftString.length() < 1) || (leftString.length() > 64)) {
        std::cout << "Left part length cannot be less than 1 and more than 64 symbols" << std::endl;
        return false;
    }

    if (leftString[0] == '.') {
        std::cout << "First symbol cannot be a point" << std::endl;
        return false;
    }





    for (int i = 0; i < leftString.length(); i++) {

        leftDictCounter = 0;


        if ((leftString[i] == '.') && (leftString[i+1] == '.')) {
            std::cout << "Two points cannot be placed one after another" << std::endl;
            return false;
        }



        for (int j = 0; j < dictionaryLeft.length(); j++) {

            if (leftString[i] == dictionaryLeft[j]) {
                leftDictCounter++;
                break;
            }

        }
        if ((leftDictCounter) == 0) {
            std::cout << "Wrong symbol in the left part" << std::endl;
            return false;


        }
    }
    return true;


}

bool is_RightString(std::string rightString) {
    std::string dictionaryRight = "ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghigklmnopqrstuvwxyz0123456789-.";
    int rightDictCounter;


    if ((rightString.length() < 1) || (rightString.length() > 63)) {
        std::cout << "Right part length cannot be less than 1 and more than 63 symbols" << std::endl;
        return false;
    }

    if (rightString[rightString.length() - 1] == '.') {
        std::cout << "Last symbol cannot be a point" << std::endl;
        return false;
    }





    for (int i = 0; i < rightString.length(); i++) {

        rightDictCounter = 0;


        if ((rightString[i] == '.') && (rightString[i+1] == '.')) {
            std::cout << "Two points cannot be placed one after another" << std::endl;
            return false;
        }



        for (int j = 0; j < dictionaryRight.length(); j++) {

            if (rightString[i] == dictionaryRight[j]) {
                rightDictCounter++;
                break;
            }

        }
        if ((rightDictCounter) == 0) {
            std::cout << "Wrong symbol in the left part" << std::endl;
            return false;


        }
    }
    return true;


}

bool is_correct(std::string email) {
    int atCounter = 0;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            atCounter ++;
        }
    }
    if (atCounter !=1) {
        std::cout << "Less than 1 or more than 1 @ symbol" <<std::endl;
        return false;
    }

    if (email[email.length() - 1] == '@') {
        std::cout << "@ cannot be the last symbol" << std::endl;
        return false;
    }

    std::string left;
    std::string right;

    left = leftString(email);
    right = rightString(email, left);


    if ((is_LeftString(left)) && (is_RightString(right))) {
        return true;
    } else {
        return false;
    }


}

int main() {

    std::string email;
   // std::string leftTest;
   // std::string rightTest;

    std::cout << "Enter an email address" << std::endl;
    std::getline(std::cin, email);

  // leftTest = leftString(email);
  //  rightTest = rightString(email, leftTest);

    if (is_correct(email)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }


  //  std::cout << leftTest << std::endl;
  //  std::cout << rightTest << std::endl;
}

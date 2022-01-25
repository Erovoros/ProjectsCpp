#include <iostream>

int main() {
    float numbers[15];
    float temp;

    std::cout << "Enter 15 floats" << std::endl;

    for (int i = 0; i < 15; i++) {
        std::cin >> numbers[i];
    }

    for (int i = 0; i < 15; i++) {

        for (int j = 0; j < 15; j++) {
            if (numbers[j + 1] > numbers[j]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 15; i++) {
        std::cout << numbers[i] << std::endl;
    }
}

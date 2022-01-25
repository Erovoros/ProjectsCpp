#include <iostream>

int main() {
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int min = numbers[0];
    int max = numbers[0];
    int realSum = 0;
    int sum = 0;
    int result;

    for (int i = 0; i < 15; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }

        if (numbers[i] > max) {
            max = numbers[i];
        }

        sum += numbers[i];
    }

    for (int i = min; i <= max; i++) {
        realSum += i;
    }

    result = sum - realSum;

    std::cout << result << std::endl;


}
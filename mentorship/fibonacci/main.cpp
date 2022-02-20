#include <iostream>

int fib(int number) {
    if ((number == 1) || (number == 0)) {
        return number;
    } else {
        return (fib(number-1) + fib(number-2));
    }
}



int main() {
    int i = 0;
    int number;

    std::cout << "Enter number" << std::endl;
    std::cin >> number;
    std::cout << "Fibonacci series: ";
    while (i < number) {
        std::cout << " " << fib(i);
        i++;
    }

}

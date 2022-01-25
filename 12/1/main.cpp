#include <iostream>



int main() {
    std::string people[10];
    int room[3];


    std::cout << "Enter ten names"  << std::endl;


    for (int i = 0; i < 10; i++) {
        std::cin >> people[i];
    }
    std::cout << "Enter three rooms: "  << std::endl;

    for (int j = 0; j < 3; j++) {
        std::cin >> room[j];
        if (room[j]>0 && room[j] <= 10) {
            std::cout << people[room[j] - 1] << std::endl;
        }
        else {
            std::cout << "Incorrect number" << std::endl;
        }
    }





}
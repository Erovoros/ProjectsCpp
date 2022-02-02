#include <iostream>
#include <vector>

int main() {
    int n;
    int m;
    int j = 0;
    int counter = 0;

    std::cout << "Enter vector length" << std::endl;

    std::cin >> n;

    std::vector<int> vec(n);

    std::cout << "Enter " << n << " elements of vector:" << std::endl;

    for (int i = 0; i < vec.size(); i++) {
        std::cin >> vec[i];
    }

    std::cout << "Enter a number to remove" << std::endl;

    std::cin >> m;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == m) {
            counter++;

        }
    }

    //declare a new vector counter elements less than original vector

    std::vector<int> newVec(n - counter);

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != m) {
            newVec[j] = vec[i];
            j++;
        }
    }


    for (int i = 0; i < newVec.size(); i++) {
        std::cout << newVec[i] << std::endl;
    }


}

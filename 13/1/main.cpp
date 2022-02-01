#include <iostream>
#include <vector>

int main() {
    int n;
    int m;

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
            vec.erase(vec.begin() + i);
            i = 0;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }


}

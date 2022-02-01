#include <iostream>
#include <vector>

int main() {

    std::vector<int> vec(20);

    int i = 0;
    int temp;

    while (true) {
        std::cin >> temp;

        if ((i == 20) && (temp != -1)) {
            vec.erase(vec.begin());
            i = 19;
            vec.resize(vec.size() + 1);
        }

        if (temp == -1) {
            break;
        }

        vec[i] = temp;
        i++;

    }

    if (i < 20) {
        for (int j = 20; j > i; j--) {
            vec.pop_back();
        }
    }


    for (int j = 0; j < vec.size(); j++) {
        std::cout << vec[j] << std::endl;
    }

}

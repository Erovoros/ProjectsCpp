#include <iostream>
#include <vector>

int main() {

    std::vector<int> vec(20);
    std::vector<int> newVec(20);


    int temp;
    int result;
    int j = 0;
    int k = 0;
    int i = 0;

    for (i;;) {

        std::cin >> result;

        if (result == -1) {
            break;
        }

        temp = i % vec.size();

        vec[temp] = result;
        i++;

    }

    if (i < vec.size()) {
        vec.resize(i);
        for (int m = 0; m < vec.size(); m++) {
            std::cout << vec[m] << std::endl;
        }
        return 0;

    }


    for (int n = temp + 1; n < vec.size(); n++) {

        newVec[j] = vec[n];
        j++;
    }

    for (j, k; j < newVec.size(); j++, k++) {
        newVec[j] = vec[k];
    }


    for (int m = 0; m < newVec.size(); m++) {
        std::cout << newVec[m] << std::endl;
    }


}

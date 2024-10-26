#include <iostream>
#include <vector>

void print(std::vector<int> list) {
    for (auto &i : list) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

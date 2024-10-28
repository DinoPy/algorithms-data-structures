#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

std::vector<int> test_list = {9, 8, 7, 6, 5, 4, 3, 2, 1};
void print(std::vector<int> list) {
    for (auto &i : list) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

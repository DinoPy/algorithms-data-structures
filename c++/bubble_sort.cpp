#include <iostream>
#include <vector>
#include "./helper_functions.cpp"

std::vector<int> test_list = {9, 8, 7, 6, 5, 4, 3, 2, 1};

std::vector<int> bubble_sort_1(std::vector<int> list) {
    bool swapping = true;
    size_t end = list.size();
    while (swapping) {
        swapping = false;
        for (int i = 1; i < end; ++i) {
            if (list[i - 1] > list[i]) {
                auto temp = list[i];
                list[i] = list[i - 1];
                list[i - 1] = temp;
                swapping = true;
            }
        }
        end -= 1;
    }
    return list;
}


int main(int argc, char *argv[]) {
    std::cout << "Original list: ";
    print(test_list);
    std::cout << "\nOrdered list: ";
    print(bubble_sort_1(test_list));
    std::cout << std::endl;
    return 0;
}

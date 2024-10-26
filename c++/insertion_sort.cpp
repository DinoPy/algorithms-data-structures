#include "./helper_functions.cpp"

std::vector<int> test_list = {9, 8, 7, 6, 5, 4, 3, 2, 1};

template <class T> std::vector<T> insertion_sort(std::vector<T> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int j = i;
        while (j > 0 && nums[j - 1] > nums[j]) {
            auto temp = nums[j - 1];
            nums[j - 1] = nums[j];
            nums[j] = temp;
            j -= 1;
        }
    }

    return nums;
}

int main(int argc, char *argv[]) {
    std::cout << "Unordered: ";
    print(test_list);
    std::cout << ". Ordered: ";
    print(insertion_sort(test_list));
    std::cout << std::endl;
    return 0;
}

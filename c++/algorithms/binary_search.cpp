#include "./helper_functions.cpp"
#include <iostream>
#include <vector>

std::vector<int> test_list = {1, 2,  3,  4,  5,  6,  7, 8,
                              9, 10, 11, 12, 13, 14, 15};

bool binary_search(std::vector<int> nums, int target) {
    if (nums.size() == 0)
        return false;

    size_t mid = nums.size() / 2;
    if (nums[mid] == target)
        return true;
    if (nums[mid] < target)
        return binary_search(
            std::vector<int>(nums.begin() + mid + 1, nums.end()), target);
    else
        return binary_search(std::vector<int>(nums.begin(), nums.begin() + mid),
                             target);
}

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            std::cout << "mid: " << mid << " s: " << s << " e: " << e << std::endl;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else {
                e = mid - 1;
            }
        }
        return -1;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    for (int i = -1; i < 18; ++i) {
        bool found = binary_search(test_list, i);
        std::cout << i << (found == 1 ? "Found" : "Not found") << std::endl;
        std::cout << s.search(test_list, i) << std::endl;
    }
    return 0;
}

#include "./helper_functions.cpp"
#include <cmath>

template <class T>
std::vector<T> merge(std::vector<T> nums1, std::vector<T> nums2) {
    std::vector<T> final;
    final.reserve(nums1.size() + nums2.size());
    int i = 0, j = 0;
    while (nums1.size() > i && nums2.size() > j) {
        if (nums1[i] < nums2[j]) {
            final.push_back(nums1[i]);
            i += 1;
        } else {
            final.push_back(nums2[j]);
            j += 1;
        }
    }

    while (i < nums1.size()) {
        final.push_back(nums1[i]);
        i += 1;
    }
    while (j < nums2.size()) {
        final.push_back(nums2[j]);
        j += 1;
    }
    return final;
}

template <class T> std::vector<T> merge_sort(std::vector<T> nums) {
    if (nums.size() < 2)
        return nums;

    auto sorted_left_side = merge_sort(
        std::vector<T>(nums.begin(), nums.begin() + floor(nums.size() / 2)));
    auto sorted_right_side = merge_sort(
        std::vector<T>(nums.begin() + floor(nums.size() / 2), nums.end()));
    return merge(sorted_left_side, sorted_right_side);
}

int main(int argc, char *argv[]) {
    std::cout << "Unordered: ";
    print(test_list);
    std::cout << "\nOrdered: ";
    print(merge_sort(test_list));
    std::cout << std::endl;
    return 0;
}

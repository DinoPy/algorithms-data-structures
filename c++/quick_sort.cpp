#include "./helper_functions.cpp"

template <class T> int partition(std::vector<T> &nums, int s, int e) {
    T pivot = nums[e];
    int i = 0;
    for (int j = s; j < e; ++j) {
        if (nums[j] < pivot) {
            auto temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i += 1;
        }
    }
    auto temp = nums[i];
    nums[i] = nums[e];
    nums[e] = temp;
    return i;
}

template <class T>
std::vector<T> quick_sort(std::vector<T> &nums, int s, int e) {
    if (s < e) {
        int pivot = partition(nums, s, e);
        quick_sort(nums, s, pivot - 1);
        quick_sort(nums, pivot + 1, e);
    }

    return nums;
}

int main(int argc, char *argv[]) {
    cout << "Unoredered: ";
    print(test_list);
    cout << ".Oredered: ";
    print(quick_sort(test_list, 0, test_list.size() - 1));
    cout << endl;

    return 0;
}

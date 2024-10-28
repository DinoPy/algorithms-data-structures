#include "./helper_functions.cpp"

template<class T>
vector<T> selection_sort(vector<T>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int smallest_index = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[smallest_index])
                smallest_index = j;
        }

        auto temp = nums[i];
        nums[i] = nums[smallest_index];
        nums[smallest_index] = temp;
    }
    return nums;
}

int main (int argc, char *argv[]) {
    cout << "Unordered: ";
    print(test_list);
    cout << "Ordered: ";
    print(selection_sort(test_list));
    cout << endl;

    return 0;
}

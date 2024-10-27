const test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1]

const selection_sort = (nums: number[]): number[] => {
    for (let i = 0; i < nums.length; i++) {
        let smallest_index = i;
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[j] < nums[smallest_index]) {
                smallest_index = j;
            }
        }
        [nums[smallest_index], nums[i]] = [nums[i], nums[smallest_index]];
    }
    return nums;
}

console.log(`Unoredered: ${test_list}. Ordered: ${selection_sort(test_list)}`);

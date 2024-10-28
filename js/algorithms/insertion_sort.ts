const test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1];

const insertion_sort = (nums: number[]) => {
    for (let i = 0; i < nums.length; i++) {
        let j = i;
        while (j > 0 && nums[j-1] > nums[j]) {
            [nums[j-1], nums[j]] = [nums[j], nums[j-1]];
            j -= 1
        }
    }
    return nums
}

console.log(`Unordered: ${test_list}. Ordered: ${insertion_sort(test_list)}`)

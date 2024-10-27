const test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1];

const quick_sort = (nums: number[], s: number, e: number): number[] => {
    if (s < e) {
        const pivot = partition(nums, s, e);
        quick_sort(nums, s, pivot - 1);
        quick_sort(nums, pivot + 1, e);
    }
    return nums
}

const partition = (nums: number[], s: number, e: number): number => {
    const pivot = nums[e];
    let i = 0;

    for (let j = 0; j <= e; j++) {
        if (nums[j] < pivot) {
            [nums[j], nums[i]] = [nums[i], nums[j]];
            i += 1;
        }
    }
    [nums[e], nums[i]] = [nums[i], nums[e]];

    return i;
}

console.log(`Unordered: ${test_list}. Ordered: ${quick_sort(test_list, 0, test_list.length - 1)}`);

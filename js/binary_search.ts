const test_list: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

const binary_search = (nums: [], target: number) => {
    if (nums.length === 1) {
        if (nums[0] === target)
            return true
        else
            return false
    }
    const mid = Math.floor(nums.length / 2)
    if (nums[mid] > target)
        return binary_search(nums.slice(0, mid), target);
    else if (nums[mid] <= target)
        return binary_search(nums.slice(mid), target);
    return false
}

for (let i = -3; i < 18; i++) {
    console.log(i, binary_search(test_list, i));
}

const test_list = [5, 4, 3, 2, 1];

const merge_sort = (nums: []) => {
    if (!Array.isArray(nums))
        throw new Error("input list is not of type list");

    if (nums.length < 2)
        return nums

    const sorted_left_side = merge_sort(nums.slice(0, Math.floor(nums.length / 2)))
    const sorted_right_side = merge_sort(nums.slice(Math.floor(nums.length / 2)))
    return merge(sorted_left_side, sorted_right_side)
}

const merge = (nums1: [], nums2: []) => {
    let final: number[] = []
    let [i, j] = [0, 0]
    while (nums1.length > i && nums2.length > j) {
        if (nums1[i] < nums2[j]) {
            final.push(nums1[i])
            i += 1
        } else {
            final.push(nums2[j])
            j += 1
        }
    }
    final = final.concat(nums1.slice(i))
    final = final.concat(nums2.slice(j))
    return final
}

console.log(`Unordered: ${test_list}. Ordered: ${merge_sort(test_list)}`)




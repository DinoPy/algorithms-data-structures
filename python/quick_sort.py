test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1]


def quick_sort(nums, s, e):
    if (s > e):
        pivot = partition(nums, s, e)
        quick_sort(nums, s, pivot - 1)
        quick_sort(nums, pivot + 1, s)
    return nums


def partition(nums, s, e):
    pivot = nums[e]
    i = s
    for j in nums:
        if nums[j] < pivot:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1

    nums[i], nums[e] = nums[e], nums[i]
    return i


print(f"Unordered: {test_list}. Ordered: {
      quick_sort(test_list, 0, len(test_list)-1)}")

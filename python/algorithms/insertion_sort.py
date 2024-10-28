test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1]


def insertion_sort(nums):
    for i in range(len(nums)):
        j = i
        while j > 0 and nums[j-1] > nums[j]:
            nums[j-1], nums[j] = nums[j], nums[j-1]
            j -= 1
    return nums


print(f"Unordered: {test_list}. Ordered: {insertion_sort(test_list)}")

test_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]


def binary_search(nums, target):
    if len(nums) == 1:
        if nums[0] == target:
            return True
        else:
            return False
    mid = len(nums)//2
    if nums[mid] == target:
        return True
    if nums[mid] > target:
        return binary_search(nums[:mid], target)
    elif nums[mid] <= target:
        return binary_search(nums[mid:], target)

    return False


for i in range(-3, 18):
    print(i, binary_search(test_list, i))

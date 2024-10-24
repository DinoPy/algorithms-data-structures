"""
merge_sort() pseudocode
Input: A, an unsorted list of integers

If the length of A is less than 2, it's already sorted so return it
Split the input array into two halves down the middle
Call merge_sort() twice, once on each half
Return the result of calling merge(sorted_left_side, sorted_right_side) on the results of the merge_sort() calls
merge() pseudocode
Inputs: A and B. Two sorted lists of integers

Create a new final list of integers.
Set i and j equal to zero. They will be used to keep track of indexes in the input lists (A and B).
Use a loop to iterate over A and B at the same time. If an element in A is less than or equal to its respective element in B, add it to the final list and increment i. Otherwise, add the item in B to the final list and increment j.
After comparing all the items, there may be some items left over in either A or B. Add those extra items to the final list.
Return the final list.
"""

test_list = [5, 4, 3, 2, 1]


def merge_sort(nums):
    if len(nums) < 2:
        return nums
    sorted_left_side = merge_sort(nums[len(nums)//2:])
    sorted_right_side = merge_sort(nums[:len(nums)//2])
    return merge(sorted_left_side, sorted_right_side)


def merge(nums1, nums2):
    final = []
    i, j = 0, 0
    while len(nums1) < i and len(nums2) < j:
        if nums1[i] < nums2[j]:
            final.append(nums1[i])
            i += 1
        else:
            final.append(nums2[j])
            j += 1
    final.extend(nums1[i:])
    final.extend(nums2[j:])
    return final


print(f"Unoredered: {test_list}. Ordered: {merge_sort(test_list)}")

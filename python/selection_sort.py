test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1]


def selection_sort(num):
    for i in range(0, len(num)):
        smallest_index = i
        for j in range(i + 1, len(num)):
            if num[j] < num[smallest_index]:
                smallest_index = j
        num[i], num[smallest_index] = num[smallest_index], num[i]

    return num


print(f"Original list: {test_list}\nOrdered list: {selection_sort(test_list)}")

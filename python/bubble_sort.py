test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1]


def bubble_sort_1(list):
    swapping = True
    end = len(list)
    while swapping:
        swapping = False
        for i in range(1, end):
            if list[i] < list[i-1]:
                list[i], list[i-1] = list[i-1], list[i]
                swapping = True
        end -= 1

    return list


print(f"Original list: {test_list}\nOrdered list: {bubble_sort_1(test_list)}")

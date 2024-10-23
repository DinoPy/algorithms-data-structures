test_list = [9, 8, 7, 6, 5, 4, 3, 2, 1]

const bubble_sort_1 = (list) => {
    swapping = true;
    end = list.length;
    while (swapping) {
        swapping = false;
        for (let i = 1; i < end; i++) {
            if (list[i - 1] > list[i]) {
                temp = list[i]
                list[i] = list[i - 1]
                list[i - 1] = temp
            }
            swapping = true;
        }
        end -= 1;
    }
    return list
}

console.log(`Original list: ${test_list}\nOrdered list: ${bubble_sort_1(test_list)}`)

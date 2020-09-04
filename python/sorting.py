# Basic exercise to implement the bubble sort algorithm in Python 3.

import random

manual_test_cases = [
    ("None list", None, []),
    ("Empty list", [], []),
    ("Single element list", [1], [1]),
    ("Test case #1", [2, 1], [1, 2]),
    ("Test case #2", [2, 1, 5, 60, 70], [1, 2, 5, 60, 70]),
    ("Test case #3", [-50, -60, 0, 45, 34, 33], [-60, -50, 0, 33, 34, 45])
]

RANDOM_TEST_CASES = 100

def build_random_list(RANDOM_LIST_LEN=10000, RANDOM_RANGE=(-5000, 5000)):
    # Cases for empty and 1 item list have already been tested manually
    list_len = random.randrange(2, RANDOM_LIST_LEN)
    list = []

    for i in range(list_len):
        list.append(random.randrange(*RANDOM_RANGE))

    return list, list_len

def test(input, actual, expected, message="Assertion error"):

    if actual != expected:
        print(f"Execution error, \"{message}\"")
        print(f"> Input:    {input}")
        print(f"> Expected: {expected}")
        print(f"> Actual:   {actual}")


def insertion_sort(list):
    """
    This is a function that sorts the given list using the insertion algorithm.
    """
    if not list or len(list) == 0:
        return []
    if len(list) == 1:
        return list

    print(f"input list = {list}")

    for i in range(len(list) - 1):
        if list[i+1] < list[i]:
            # we need to move i+1 before i
            temp = list.pop(i + 1)

            if i == 0:
                list.insert(-1, temp)
                continue

            for j in range(i):
                if list[j] > temp:
                    list.insert(j, temp)

        print(f"> @{i}list = {list}")

    return list


def bubble_sort(list):
    """
    This is a function that sorts the given list using the bubble sort method.
    """
    if not list or len(list) == 0:
        return []
    if len(list) == 1:
        return list

    end = False
    swapped = False

    while not end:

        for i in range(len(list) - 1):

            if list[i] > list[i+1]:
                tmp = list[i]
                list[i] = list[i+1]
                list[i+1] = tmp
                swapped = True

        end = not swapped
        swapped = False

    return list


if __name__ == "__main__":

    # BUBBLE SORT: Manual test case validation
    for test_case in manual_test_cases:

        print(f"### test_case = {test_case}, input = {test_case[1]}")

        input = None
        if test_case[1] is not None:
            input = test_case[1].copy()

        actual = bubble_sort(input)
        test(test_case[1], actual, test_case[2], message=test_case[0])

        input = None
        if test_case[1] is not None:
            input = test_case[1].copy()

        actual = insertion_sort(input)
        test(test_case[1], actual, test_case[2], message=test_case[0])

    # Validation against 'sort' function in Python
    """
    for i in range(RANDOM_TEST_CASES):
        list, list_len = build_random_list()
        print(f"Testing random case #{i} ({(i/RANDOM_TEST_CASES):.2f}%), list_len = {list_len}")
        test(list, sorted(list), message=f"Random test case #{i}")
    """

#/usr/bin/env python3
#! @author: Lam Duong
# Algorithm implementations for Lam's Algorithm channel

def johnsonTrotter(n: int) -> list:
    """Johnson-Trotter Algorithm:
    Given a number, generate a permutation sequence from 1 to n.
    In this case, True is left arrow."""

    # Set up representation of numbers and arrows
    result = list()
    numbers = list()
    arrows = list()
    for i in range(n):
        numbers.append(i + 1)
        arrows.append(True)
    result.append(numbers)

    k = largestMobileElement(numbers, arrows)
    while (k != -1):
        k = largestMobileElement(numbers, arrows)
        direction = -1 if numbers[k] else 1
        swapElements(numbers, k, k+direction)
        # Reverse the direction of all elements larger than k
        for i in range(len(numbers)):
            if (numbers[i] > numbers[k]):
                arrows[i] = not arrows[i]
        result.append(numbers)

    return result

def largestMobileElement(numbers: list, arrows: list) -> int:
    """Helper function for Johnson-Trotter:
    Check to see if the number sequence has a mobile element by getting the
    largest mobile element. If there are no mobile elements, return -1.
    To ensure the runtime of the algorithm, this function will need O(n)
    runtime. """

    k = -1 # No mobile element state
    # Only return k if the a number points to a smaller adjacent number.
    for index in range(len(numbers)):
        if (((arrows[index] == True)
            and (index != 0)
            and (numbers[index - 1] < numbers[index]))
        or  ((arrows[index] == False)
            and (index != len(numbers)-1)
            and (numbers[index] > numbers[index+1]))):
            if (k == -1):
                k = index
            elif (numbers[index] > numbers[k]):
                k = index
    return k

def swapElements(t_list: list, index1: int, index2: int):
    """ Helper function to swap elements in a list based on indices. """
    temp = t_list[index1]
    t_list[index1] = t_list[index2];
    t_list[index2] = temp

johnsonTrotter(3)

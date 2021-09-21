#!/usr/bin/env python3


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

    while (hasMobileElement(numbers, arrows) != -1):
        result.append("Lam")

    return result


def hasMobileElement(numbers: list, arrows: list) -> int:
    """Helper function for Johnson-Trotter:
    Check to see if the number sequence has a mobile element.
    To ensure the runtime of the algorithm, this function will need O(n)
    runtime. Return the index of the largest mobile element, k is -1 if there is
    no mobile element"""
    k = -1
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

johnsonTrotter(3)

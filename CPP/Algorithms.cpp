/*
** Author: Lam Duong
*/

#include "Algorithms.hpp"

/**
 * Johnson-Trotter algorithm
 * @brief Find a list of permutations of n unique digits
 * @param n, the length of the sequence of numbers
 * @returns a vector containing all the permutations from 1 to n */
std::vector<std::vector<int>> Algorithms::johnsonTrotter(int n)
{
    int k = n;
    std::vector<std::vector<int>> result;
    std::vector<std::pair<int, bool>> numberSequence;

    for (int i = 1; i <= n; i++)
    {
        numberSequence.push_back(std::pair<int, bool>(i, true));
    }
    result.push_back(johnsonTrotterGetNumbers(numberSequence));

    while (k != -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (numberSequence[i].first == k)
            {
                int pointedIndex;
                if (numberSequence[i].second)
                    pointedIndex = i - 1;
                else
                    pointedIndex = i + 1;

                int tempNum = numberSequence[pointedIndex].first;
                bool tempArrow = numberSequence[pointedIndex].second;

                numberSequence[pointedIndex].first = numberSequence[i].first;
                numberSequence[pointedIndex].second = numberSequence[i].second;
                numberSequence[i].first = tempNum;
                numberSequence[i].second = tempArrow;
                break;
            }
        }
        // Flip any thing that is greater than k, O(n)
        for (int i = 0; i < n; i++)
        {
            if (numberSequence[i].first > k)
            {
                numberSequence[i].second = !numberSequence[i].second;
            }
        }
        result.push_back(johnsonTrotterGetNumbers(numberSequence));
        k = johnsonTrotterFindK(numberSequence);
    }

    return result;
}

/* Create a new vector that is a copy of the number of sequence with just
 * the numbers, and no boolean. */
std::vector<int>
Algorithms::johnsonTrotterGetNumbers(const std::vector<std::pair<int, bool>>& numberSequence)
{
    auto result = new std::vector<int>(); // allocate on heap
    for (int i = 0; i < (int)numberSequence.size(); i++)
    {
        (*result).push_back(numberSequence[i].first);
    }
    return *result;
}

/* Find the largest mobile element. If the bool in the pair is true, the
arrow points left and points right if it's false.*/
int Algorithms::johnsonTrotterFindK(std::vector<std::pair<int, bool>>& numberSequence)
{
    int k = -1;
    for (int i = 0; i < (int)numberSequence.size(); i++)
    {
        int num = numberSequence[i].first;
        bool arrow = numberSequence[i].second;
        if (i == 0)
        {
            if (!arrow && (num > numberSequence[i + 1].first))
                if (num > k)
                    k = num;
        }
        else if (i != (int)numberSequence.size() - 1)
        {
            if (((arrow && (num > numberSequence[i - 1].first)) ||
                 (!arrow && (num > numberSequence[i + 1].first))))
                if (num > k)
                    k = num;
        }
        else
        {
            if (arrow && (num > numberSequence[i - 1].first))
                if (num > k)
                    k = num;
        }
    }
    return k;
}

/** Heap's Algorithm:
 * @brief Find all permutations of a given integer, n. This function is used
 * to set up the global array required by the algorithm.
 * @param n the size of the permutation */
void Algorithms::heapsAlgorithm(const int n)
{
    std::vector<int> globalArray;
    std::vector<std::vector<int>> result;

    // Construct our first set of numbers
    for (int i = 1; i <= n; i++)
    {
        globalArray.push_back(i);
    }
    heapsPermutation(n, globalArray);
}

/**
 * @brief Recursive function that does the actual work for Heap's Algorithm.
 * @param n the size of the permutation
 * @param array the global array that resulting permutation is */
void Algorithms::heapsPermutation(const int n, std::vector<int>& array)
{
    if (n == 1)
    {
        for (int i = 0; i < (int)array.size(); i++)
        {
            std::cout << array[i];
        }
        std::cout << std::endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            heapsPermutation(n - 1, array);
            if (n % 2 != 0)
            {
                auto temp = array[0];
                array[0] = array[n - 1];
                array[n - 1] = temp;
            }
            else
            {
                auto temp = array[i - 1];
                array[i - 1] = array[n - 1];
                array[n - 1] = temp;
            }
        }
    }
}

/**
 * @brief There is a row of n coins whose values are some positive integers, c1,
 * c2, ...., cn, not necessarily distinct. The goal is to pick up the maximum
 * amount of money subject to the constraint that no two coins adjacent in the
 * initial row can be picked up.
 * @param coins non-unique and positive integers. */
int Algorithms::coinRow(std::vector<int>& coins)
{
    std::vector<int> result{0, coins[0]}; // dynamic programming memoization
    auto n = coins.size();
    for (int i = 2; i < n; i++)
    {
        result.push_back(std::max(coins[i] + result[i - 2], result[i - 1]));
    }
    return result[result.size() - 1];
}

int Algorithms::changeMaking(std::vector<int>& denominations, int amount)
{
    std::vector<int> result{0};
    for (int i = 0; i < amount; i++)
    {
        int temp = INT32_MAX, j = 1;
        while (j <= denominations[denominations.size() - 1] &&
               i >= denominations[j])
        {
            temp = std::min(result[i - denominations[j]], temp);
            j++;
        }
        if (temp == INT32_MAX)
            result[i] = temp;
        else
            result[i] = temp + 1;
    }
    if (result[amount] == INT32_MAX)
    {
        return -1;
    }
    else
    {
        return result[amount];
    }
}

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int n = std::atoi(argv[argc - 1]);
        // Insert arg here
    }
    auto vector = std::vector<int>{1, 5, 10, 25};
    std::cout << Algorithms::changeMaking(vector, 6);

    return 0;
}

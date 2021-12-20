/*
** Author: Lam Duong
*/

#include "Algorithms.hpp"

/**
 * @brief Johnson-Trotter algorithm:
 *
 * @param n, the length of the sequence of numbers
 * @returns a vector containing all the permutations from 1 to n
 */
std::vector<std::vector<int>> Algorithms::johnsonTrotter(int n)
{
    int k = n;
    std::vector<std::vector<int>> result;
    std::vector<std::pair<int, bool>> numberSequence;

    for (int i = 1; i <= n; i++)
    {
        numberSequence.push_back(std::pair<int, bool>(i, true));
    }
    result.push_back(getNumbers(numberSequence));

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
        result.push_back(getNumbers(numberSequence));
        k = findK(numberSequence);
    }

    return result;
}

/* Create a new vector that is a copy of the number of sequence with just
 * the numbers, and no boolean. */
std::vector<int>
Algorithms::getNumbers(const std::vector<std::pair<int, bool>>& numberSequence)
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
int Algorithms::findK(std::vector<std::pair<int, bool>>& numberSequence)
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

/*
** Heap's Algorithm:
** ----------------------------------------------------------------------
** Find all permutations of a given integer, n. This function is used to
** set up the global array required by the algorithm.
*/
void Algorithms::heapsAlgorithm(const int n)
{
    std::vector<int> globalArray;

    // Construct our first set of numbers
    for (int i = 1; i <= n; i++)
    {
        globalArray.push_back(i);
    }

    heapsPermutation(n, globalArray);
}

/*
** Recursive function that does the actual work for Heap's Algorithm.
*/
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

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int n = std::atoi(argv[argc - 1]);
        Algorithms::heapsAlgorithm(n);
    }
    return 0;
}

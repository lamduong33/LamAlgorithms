/*
** Author: Lam Duong
*/
#include <iostream>
#include <vector>

class Algorithms
{
public:
    /**
     * Johnson-Trotter algorithm
     *------------------------------------------------------------------------------
     * input: n, the length of the sequence of numbers
     * output: a vector containing all the permutations from 1 to n
     */
    static std::vector<std::vector<int>> johnsonTrotter(int n)
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
            for (int i = 0; i < n; i++) {
                if (numberSequence[i].first > k) {
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
    static std::vector<int>
    getNumbers(const std::vector<std::pair<int, bool>> &numberSequence)
    {
        auto result = new std::vector<int>(); // allocate on heap
        for (int i = 0; i < numberSequence.size(); i++)
        {
            (*result).push_back(numberSequence[i].first);
        }
        return *result;
    }

    /* Find the largest mobile element. If the bool in the pair is true, the
    arrow points left and points right if it's false.*/
    static int findK(std::vector<std::pair<int, bool>> numberSequence)
    {
        int k = -1;
        for (int i = 0; i < numberSequence.size(); i++)
        {
            int num = numberSequence[i].first;
            bool arrow = numberSequence[i].second;
            if (i == 0)
            {
                if (!arrow && (num > numberSequence[i + 1].first))
                    if (num > k) k = num;
            }
            else if (i != numberSequence.size() - 1)
            {
                if (((arrow && (num > numberSequence[i-1].first)) ||
                    (!arrow && (num > numberSequence[i+1].first))))
                    if(num > k) k = num;
            }
            else
            {
                if (arrow && (num > numberSequence[i - 1].first))
                   if (num > k) k = num;
            }
        }
        return k;
    }
};


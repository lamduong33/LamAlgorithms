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

        }
        return result;
    }

    /* Create a new vector that is a copy of the number of sequence with just
     * the numbers, and no boolean. */
    static std::vector<int>
    getNumbers(const std::vector<std::pair<int, bool>> &numberSequence)
    {
        auto result = new std::vector<int>(); // NOTE: allocate on heap just in case
        for (int i = 0; i < numberSequence.size(); i++)
        {
            (*result).push_back(numberSequence[i].first);
        }
        return *result;
    }

    static int findK(std::vector<std::pair<int, bool>> numberSequence)
    {
        int k = -1;
        for (int i = 0; i < numberSequence.size(); i++)
        {

        }
        return k;
    }
};

int main(int argc, char *argv[])
{
    auto a = Algorithms::johnsonTrotter(3);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            std::cout << a[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include <vector>

namespace Algorithms // feel free to change this name if you ever want to use
                     // this.
{
std::vector<std::vector<int>> johnsonTrotter(int n);
std::vector<int>
getNumbers(const std::vector<std::pair<int, bool>>& numberSequence);
int findK(std::vector<std::pair<int, bool>>& numberSequence);

/*----------------------------------------------------------------------*/
void heapsAlgorithm(const int n);
void heapsPermutation(const int n, std::vector<int>& array);

int changeMaking(std::vector<int> denominations, int amount);

}; // namespace Algorithms

#endif // ALGORITHMS_HPP

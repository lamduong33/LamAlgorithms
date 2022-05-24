#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <bits/stdc++.h>

namespace Algorithms // feel free to change this name if you ever want to use
                     // this.
{

// Sorting algorithms
void mergeSort(std::vector<int>& t_numbers);
void countingSort(std::vector<int>& t_numbers);

std::vector<std::vector<int>> johnsonTrotter(int n);
std::vector<int>
johnsonTrotterGetNumbers(const std::vector<std::pair<int, bool>>& numberSequence);
int johnsonTrotterFindK(std::vector<std::pair<int, bool>>& numberSequence);

/*----------------------------------------------------------------------*/

void heapsAlgorithm(const int n);
void heapsPermutation(const int n, std::vector<int>& array);

int changeMaking(std::vector<int>& denominations, int amount);

int coinRow(std::vector<int>& coins);

}; // namespace Algorithms

#endif // ALGORITHMS_HPP

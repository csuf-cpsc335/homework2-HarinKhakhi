#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <string>
using namespace std;

// ================== COUNT SORT ==================
vector<int> count_sort(vector<int> nums);
vector<char> count_sort(vector<char> chars);

// ================== RADIX SORT ==================
vector<int> radix_sort(vector<int> nums);
vector<string> radix_sort(vector<string> chars);

#endif
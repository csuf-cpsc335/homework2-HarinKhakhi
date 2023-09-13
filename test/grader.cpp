#include <iostream>

#include <vector>
#include <unordered_map>

#include <functional>
#include <cassert>

#include "../src/sorting_algorithms.h"
#include "input_generator.h"

using namespace std;

// ====================== Helper ======================
void print(vector<int>& nums){
    for(int num: nums)
    cout<<num<<" ";
    cout<<"\n";
}

bool isSorted(vector<int>& nums){
    for(int i=1; i<nums.size(); i++){
        if(nums[i] < nums[i-1])
        return false;
    }
    return true;
}
// ===================================================

int main(int argc, char* argv[]){
    // initialization
    srand((unsigned) time(NULL));

    int totalTests = 100;
    vector<vector<int>> testSetValues = 
        get_random_set_values(totalTests, {100, 1000}, SMALL_POSITIVE_VALUES_RANGE);

    // 1. Testing Count Sort 
    cout << "Testing Count Sort: ";
    int totalPassedCountSort = 0;
    for(vector<int> test: get_copy(testSetValues)){
        
        vector<int> sortedCountSort = count_sort(test);
        if(isSorted(sortedCountSort))
        totalPassedCountSort++;

    } 

    cout << "(" << totalPassedCountSort << " / " << totalTests << " passed)\n";

    // 2. Testing Radix Sort
    cout << "Testing Radix Sort: ";
    int totalPassedRadixSort = 0;
    for(vector<int> test: get_copy(testSetValues)){
        
        vector<int> sortedRadixSort = radix_sort(test);
        if(isSorted(sortedRadixSort))
        totalPassedRadixSort++;

    }

    cout << "(" << totalPassedRadixSort << " / " << totalTests << " passed)\n";

    if(argc > 1){
        assert(totalPassedCountSort == totalTests);
        assert(totalPassedRadixSort == totalTests);
    }

    return 0;
}
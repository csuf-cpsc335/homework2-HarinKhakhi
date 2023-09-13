#include "sorting_algorithms.h"

vector<int> count_sort(vector<int> nums){
    int n = nums.size();

    // find max element
    int max_ele = nums[0];
    for(int i=0; i<nums.size(); i++){
        max_ele = max(max_ele, nums[i]);
    }

    // make counts array
    vector<int> counts(max_ele+1, 0);
    for(int i=0; i<n; i++)
        counts[nums[i]] ++;

    // modify the count array such that, 
    // each element at each index stores the sum of previous counts.
    // now counts array will have the actual
    // position of all elements in output array
    for (int i = 1; i <= max_ele; i++)
        counts[i] += counts[i - 1];

    // build the output array
    vector<int> ans(n);
    for (int i=n-1; i>=0; i--){
        ans[counts[nums[i]]-1] = nums[i];
        --counts[nums[i]];
    }

    return ans;
}
#include "sorting_algorithms.h"

// returns the d'th digit from number
int get_digit(int num, int d){
    int p = pow(10, d);
    return (num / p) % 10;
}

void count_sort_digit(vector<int>& nums, int d){
    int n = nums.size();
    int max_ele = 10;

    vector<int> counts(max_ele+1, 0);
    for(int i=0; i<n; i++)
        counts[get_digit(nums[i], d)] ++;

    for (int i = 1; i <= max_ele; i++)
        counts[i] += counts[i - 1];

    vector<int> ans(n);
    for (int i=n-1; i>=0; i--){
        int digit = get_digit(nums[i], d);
        ans[counts[digit]-1] = nums[i];
        --counts[digit];
    }

    for(int i=0; i<n; i++)
        nums[i] = ans[i];
}

vector<int> radix_sort(vector<int> nums){
    int n = nums.size();

    // find the max element to get total digits
    int max_ele = nums[0];
    for(int i=0; i<n; i++){
        max_ele = max(max_ele, nums[i]);
    }

    int total_digits = ceil(log(max_ele));

    // running stable version of count sort on individual digits
    for(int d=0; d<=total_digits; d++){
        count_sort_digit(nums, d);
    }

    return nums;
}

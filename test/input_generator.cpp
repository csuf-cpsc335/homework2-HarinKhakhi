#include "input_generator.h"

using namespace std;

int get_random_value(pair<int,int> val_range){
    // rand() will return any integer, so we need to do some operation
    // to get a random value in a range
    return rand() % (val_range.second - val_range.first + 1) + val_range.first;
}

char get_random_char(){
    int ch_i = rand() % 26;
    return (char) ch_i;
}

string get_random_string(int length){
    string ans = "";
    for(int i=0; i<length; i++){
        ans += get_random_char();
    }
    return ans;
}

vector<int> get_random_values(int total, pair<int,int> val_range){        
    // generating `total` amount of random numbers in given range
    vector<int> nums;
    for(int i=0; i<total; i++){
        nums.push_back(
            get_random_value(val_range)
        );
    }

    return nums;
}

vector<int> get_partially_sorted_values(int total, pair<int,int> val_range){
    // generating `total` amount of partially sorted numbers in given range
    vector<int> nums = get_random_values(total, val_range);
    sort(nums.begin(), nums.end());

    int swaps = get_random_value({0, total*0.10});
    for(int i=0; i<swaps; i++){
        int firstIndex = get_random_value({0, total-1});
        int secondIndex = get_random_value({0, total-1});
        swap(nums[firstIndex], nums[secondIndex]);
    }

    return nums;
}

vector<string> get_random_strings(int total, pair<int,int> len_range){
    vector<string> strings;
    for(int i=0; i<total; i++){
        int length = get_random_value(len_range);
        strings.push_back(get_random_string(length));
    }
    return strings;
}

vector<vector<int>> get_random_set_values(int total, pair<int,int> n_range, pair<int,int> val_range){
    // generating `total` amount of inputs for given length range and value range
    vector<vector<int>> numsVec;
    for(int i=0; i<total; i++){
        int n = get_random_value(n_range);
        vector<int> nums = get_random_values(n, val_range);
        numsVec.push_back(nums);
    }

    return numsVec;
}

vector<vector<int>> get_partially_sorted_set_values(int total, pair<int,int> n_range, pair<int,int> val_range){
    // generating `total` amount of partially sorted inputs for given length range and value range
    vector<vector<int>> numsVec;
    for(int i=0; i<total; i++){
        int n = get_random_value(n_range);
        vector<int> nums = get_partially_sorted_values(n, val_range);
        numsVec.push_back(nums);
    }

    return numsVec;
}

vector<vector<string>> get_random_set_strings(int total, pair<int,int> n_range, pair<int,int> len_range){
    // generating `total` amount of inputs for given length range and length range
    vector<vector<string>> stringsVec;
    for(int i=0; i<total; i++){
        int n = get_random_value(n_range);
        vector<string> strings = get_random_strings(n, len_range);
        stringsVec.push_back(strings);
    }
    
    return stringsVec;
}

vector<vector<int>> get_copy(vector<vector<int>>& set){
    // generates a copy of the given set
    vector<vector<int>> copy(set);
    return copy;
}

vector<string> get_copy(vector<string>& set){
    // generates a copy of the given set
    vector<string> copy(set);
    return copy;
}
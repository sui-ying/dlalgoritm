/*
167
在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
*/

#include "../../utils/common.hpp"

vector<int> twoNums(vector<int>& nums, int target){
    int length = nums.size();
    int l= 0; 
    int r = length-1; 
    while (l<r){
        int total  = nums[l] + nums[r];
        if (total == target){
            return vector<int>{l+1, r+1};
        }
        else if (total < target){
            l++;
        }
        else{
            r--;
        }
    }
    return vector<int>{-1, -1};
}

int main(){
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>res = twoNums(nums, target);
    printVector(res);
    return 0;
}

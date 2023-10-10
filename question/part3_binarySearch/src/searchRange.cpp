/*
34. 在排序数组中查找元素的第一个和最后一个位置
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
*/

#include "../../utils/common.hpp"

/**
 * 二分查找 + 区间放大
*/
vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    int mid = -1;

    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == target){
            l = mid;
            r = mid;
            while ( l - 1 >= 0 && nums[l-1] == target) {
                l--;
            }
            while ( r + 1 <= nums.size() -1 && nums[r +1] == target) {
                r++;
            }
            return {l, r};

        } else if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        }
    }
    return {-1, -1};
}

int main(){
    vector<int> nums = {1, 3, 8, 8, 9};
    int target = 8; 
    vector<int> res = searchRange(nums, target);
    printVector(res);
    return 0;
}
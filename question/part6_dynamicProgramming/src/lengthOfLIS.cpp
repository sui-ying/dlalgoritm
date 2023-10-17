/*
300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/

#include "../../utils/common.hpp"

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;

    vector<int> dp(n, 1);
    int maxLength = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}

int main(){
    vector<int>nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}
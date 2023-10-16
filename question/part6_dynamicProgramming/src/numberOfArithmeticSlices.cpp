/*
413. 等差数列划分
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
子数组 是数组中的一个连续序列。
*/

#include "../../utils/common.hpp"

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
        return 0;
    }
    vector<int>dp(n, 0);  // 构造函数，将n个0赋值给dp: 赋初始值，dp[i]表示前i个数组成等差数列的个数,
    for (int i = 2; i < n; i++) {
        if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            dp[i] = dp[i-1] + 1;  // 状态转移方程
        }
    }
    return accumulate(dp.begin(), dp.end(), 0);  // 求和算法
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << numberOfArithmeticSlices(nums) << endl;
    return 0;
}
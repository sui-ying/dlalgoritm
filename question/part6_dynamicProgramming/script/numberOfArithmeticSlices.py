"""
413. 等差数列划分
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
子数组 是数组中的一个连续序列。
"""

def numberOfArithmeticSlices(nums):
    n = len(nums)
    if n < 3:
        return 0
    
    dp = [0] * n   # 表示前n个数可组成的等差数列的个数
    for i in range(2, n):
        if nums[i] - nums[i-1] == nums[i-1] - nums[i-2]:
            dp[i] = dp[i-1] + 1
    print(dp)
    return sum(dp)


if __name__ == '__main__':
    print(numberOfArithmeticSlices([1, 2, 3, 4, 5]))
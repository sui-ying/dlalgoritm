"""
300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
"""


def lengthOfLIS(nums):
    n = len(nums)
    if n <= 1:
        return n
    dp = [1] * n  # 1. dp[i]表示前i个数能够组成最大递增子序列的个数
    maxLength = 0
    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:  # 2. 迭代方程：当nums[i] > nums[j] && i < j时, 最大max(dp[i], dp[j] + 1)
                dp[i] = max(dp[i], dp[j] + 1)
        maxLength = max(maxLength, dp[i])

    return maxLength


if __name__ == '__main__':
    # print("code here")
    nums = [0,1,0,3,2,3]
    print(lengthOfLIS(nums))
"""
279. 完全平方数
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
"""


def numSquares(num):
    dp = [i for i in range(num + 1)]  # 1. dp[i] = n表示数字i最少可以用n个平方数和组成; # 2. 初始值数字0组成为0
    for i in range(2, num+1):
        for j in range(1, int(i**0.5) + 1):
            dp[i] = min(dp[i], dp[i - j * j] + 1)   # 迭代公式
    return dp[num]


if __name__ == '__main__':
    num = 16
    print(numSquares(num))
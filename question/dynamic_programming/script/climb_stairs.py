"""
给定一个共有 $n$ 阶的楼梯，你每步可以上 $1$ 阶或者 $2$ 阶，请问有多少种方案可以爬到楼顶
"""


def climb_stairs(n: int):
    """
    动态规划: 从前往后递推
    :param n:
    :return:
    """
    if n == 1 or n == 2:
        return n

    dp = [0] * (n+1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 2   #  dp[i] = j 表示爬n阶梯子总共的方法

    for i in range(3, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]


def climb_stairs_plus(n: int):
    """
    滚动变量
    :param n:
    :return:
    """
    if n == 1 or n == 2:
        return n

    a, b = 1, 2
    for i in range(3, n + 1):
        a, b = b, a+b
    return b


if __name__ == '__main__':
    print(climb_stairs(10))
    print(climb_stairs_plus(10))

    
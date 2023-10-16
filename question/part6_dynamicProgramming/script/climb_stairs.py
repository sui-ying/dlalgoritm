"""
给定一个共有 $n$ 阶的楼梯，你每步可以上 $1$ 阶或者 $2$ 阶，请问有多少种方案可以爬到楼顶
"""


def climb_stairs(n: int) -> int:
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


def climb_stairs_plus(n: int) -> int:
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



"""
加以限制:
给定一个共有 $n$ 阶的楼梯，你每步可以上 $1$ 阶或者 $2$ 阶，**但不能连续两轮跳 $1$ 阶**，请问有多少种方案可以爬到楼顶。
"""

def climb_stairs_constraint(n: int) -> int:
    """
    带约束爬楼梯：动态规划
    :param n:
    :return:
    """
    if n == 1 or n == 2:
        return 1
    # 初始化 dp 表，用于存储子问题的解
    dp = [[0] * 3 for _ in range(n + 1)]
    # 初始状态：预设最小子问题的解
    # 状态定义：状态 [i, j][i,j] 表示处在第 i 阶、并且上一轮跳了 j 阶，其中 j∈{1,2} 。
    # 此状态定义有效地区分了上一轮跳了1阶还是2阶，我们可以据此来决定下一步该怎么跳。
    # 当 j 等于 1 ，即上一轮跳了 1 阶时，这一轮只能选择跳 2 阶。
    #当 j 等于 2 ，即上一轮跳了 2 阶时，这一轮可选择跳 1 阶或跳 2 阶。
    dp[1][1], dp[1][2] = 1, 0   # dp[i][j] 表示爬到n阶梯总共方法
    dp[2][1], dp[2][2] = 0, 1
    # 状态转移：从较小子问题逐步求解较大子问题
    for i in range(3, n + 1):
        dp[i][1] = dp[i - 1][2]
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2]
    return dp[n][1] + dp[n][2]


if __name__ == '__main__':
    print(climb_stairs(10))
    print(climb_stairs_plus(10))
    
    print(climb_stairs_constraint(10))

    
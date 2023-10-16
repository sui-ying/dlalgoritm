"""
输入两个字符串 $s$ 和 $t$ ，返回将 $s$ 转换为 $t$ 所需的最少编辑步数。
你可以在一个字符串中进行三种编辑操作：插入一个字符、删除一个字符、替换字符为任意一个字符
"""

def edit_distance(s1: str, s2: str) -> int:
    """
    动态规划实现编辑距离
    :param s1:
    :param s2:
    :return:
    """
    if len(s1) == 0:
        return len(s2)
    if len(s2) == 0:
        return len(s1)

    # 1. 定义 dp[i][j] 表示将s1的前i个字符更改为s2的前j个字符所需的最少编辑步数
    dp = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]  
    # 2. 边界条件
    for j in range(len(s2)+1):
        dp[0][j] = j
    for i in range(len(s1)+1):
        dp[i][0] = i

    for i in range(1, len(s1)+1):
        for j in range(1, len(s2)+1):
            # 3. 转移方程
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    return dp[-1][-1]


if __name__ == '__main__':
    print(edit_distance("bag", "pack"))
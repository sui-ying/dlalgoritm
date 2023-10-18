"""
1143. 最长公共子序列
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串
"""


def longestCommonSubsequence(t1, t2):
    m = len(t1)
    n = len(t2)

    # 1. 定义dp[i][j] 表示到字符串t1[0:i] 和 t2[0:i]最长的公共子序列长度
    # 2. 初始值： i==0 or j==0, 空字符串最大子序列长度为0
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # 3. 迭代方程
    for i in range(1, m+1):
        for j in range(1, n+1):
            if t1[i-1] == t2[j-1]:  # 考虑 t1[0:i−1] t2[0:j-1]
                dp[i][j] = dp[i - 1][j - 1] + 1  # 如果相等，最长的公共子序列长度为dp[i - 1][j - 1] +1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])  # 否则，最长的公共子序列长度为 t1 或者 t2 缩小1之后的最大公共长度

    return dp[m][n]


if __name__ == '__main__':
    text1 = "abcde"
    text2 = "ace"
    print(longestCommonSubsequence(text1, text2))
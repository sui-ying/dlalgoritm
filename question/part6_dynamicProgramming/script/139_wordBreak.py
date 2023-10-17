"""
139. 单词拆分
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
"""


def wordBreak(s, wordDict):
    n = len(s)
    dp = [True] + [False] * n  # 1. 定义dp, dp[i]表示s 的前 i 位是否可以用 wordDict中的单词表示; 初始条件

    for i in range(1, n+1):
        for j in range(i):
            if dp[j] and s[j:i] in wordDict:  # 2. 转移方程
                dp[i] = True
                break  # s[j:i]在wordDict, 表示至少存在一种方法使得s 的前 i 位是否可以用 wordDict中的单词表示

    return dp[n]


if __name__ == '__main__':
    s = "applepenapple"
    wordDict = ["apple", "pen"]
    print(wordBreak(s, wordDict))
"""
221. 最大正方形
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
"""

def maximalSquare(matrix):
    
    # 1. 定义dp
    m = len(matrix)
    n = len(matrix[0])
    if m == 0 or n == 0:
        return 0

    maxSide = 0
    dp = [[0] * n for _ in range(m)]  # 表示以(i, j)为右下角能组成正方形的最大边长

    for i in range(m):
        for j in range(n):
            if matrix[i][j] == '1':
                if i == 0 or j == 0:  # 2. 边界条件: 左边和上边时只需考虑matrix[i][j]的值
                    dp[i][j] = 1
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1  # 3. 迭代公式
                maxSide = max(maxSide, dp[i][j])
    return maxSide * maxSide


if __name__ == '__main__':
    matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    print(maximalSquare(matrix))
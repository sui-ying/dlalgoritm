"""
542. 01 矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。
"""


def update01Matrix(mat):
    dp = [[float("inf")] * len(mat[0]) for _ in range(len(mat))]  # dp[i][j]表示该位置（i， j）到最近0的距离
    for i in range(len(mat)):  # 动态规划: 从左上往右下更新dp
        for j in range(len(mat[0])):
            if mat[i][j] == 0:
                dp[i][j] = 0
            else:
                if j > 0:
                    dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j])  # 从上往下更新
                if i > 0:
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j])  # 从左往右更新

    print(dp)
    for i in range(len(mat) - 1, -1, -1):  # 第二次动态规划: 从右下往左上更新dp
        for j in range(len(mat[0]) - 1, -1, -1):
            if mat[i][j] != 0:
                if j < len(mat[0]) - 1:
                    dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j])  # 从下往上更新
                if i < len(mat) - 1:
                    dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j])  # 从右往左更新
    return dp


if __name__ == '__main__':
    matrix = [[0, 0, 0], [0, 1, 0], [1, 1, 1]]
    print(update01Matrix(matrix))

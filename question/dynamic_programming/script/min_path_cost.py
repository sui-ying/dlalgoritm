"""
实现最小路径损失
"""

def min_path_cos(grid: list) -> int:
    m, n = len(grid), len(grid[0])
    dp = [[0] * n for _ in range(m)]  # dp[i][j]表示到达位置(i, j)路径步数

    dp[0][0] = grid[0][0]
    for i in range(1, m):    
        dp[i][0] = dp[i-1][0] + grid[i][0]
    for j in range(1, n):    
        dp[0][j] = dp[0][j-1] + grid[0][j]

    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]

    return dp[m-1][n-1]


def min_path_cos_plus(grid: list) -> int:
    m, n = len(grid), len(grid[0])
    dp = [0] * n
    dp[0] = grid[0][0]
    for j in range(1, m):
        dp[j] = dp[j-1] + grid[0][j]

    for i in range(1, m):
        dp[0] = dp[0] + grid[i][0]
        print(dp[0])
        for j in range(1, n):
            dp[j] = min(dp[j-1], dp[j]) + grid[i][j]
        print(dp)
    return dp[n-1]

if __name__ == '__main__':
    grid = [[1, 3, 1, 5], [2, 2, 4, 2], [5, 3, 2, 1], [4, 3, 5, 2]]
    print(min_path_cos(grid))
    print(min_path_cos_plus(grid))
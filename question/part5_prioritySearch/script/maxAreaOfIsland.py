"""
695. 岛屿的最大面积
给你一个大小为 m x n 的二进制矩阵 grid 。
岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
岛屿的面积是岛上值为 1 的单元格的数目。
计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
"""


class Solution:
    def __init__(self, grid):
        self.grid = grid

    def dfs(self, i, j) -> int:
        """
         深度优先搜索depth-first search：遍历
         """
        if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]) or grid[i][j] != 1:
            return 0
        grid[i][j] = 0
        localArea = 1
        for di, dj in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            localArea += self.dfs(i+di, j+dj)
        return localArea

    def maxAreaOfIsland(self) -> int:
        ans = 0
        for i, l in enumerate(grid):
            for j, n in enumerate(l):
                ans = max(self.dfs(i, j), ans)
        return ans


if __name__ == '__main__':
    grid =  [[0,0,1,0,0,0,0,1,0,0,0,0,0],
            [0,0,0,0,0,0,0,1,1,1,0,0,0],
            [0,1,1,0,1,0,0,0,0,0,0,0,0],
            [0,1,0,0,1,1,0,0,1,0,1,0,0],
            [0,1,0,0,1,1,0,0,1,1,1,0,0],
            [0,0,0,0,0,0,0,0,0,0,1,0,0],
            [0,0,0,0,0,0,0,1,1,1,0,0,0],
            [0,0,0,0,0,0,0,1,1,0,0,0,0]]

    solution = Solution(grid)
    print(solution.maxAreaOfIsland())
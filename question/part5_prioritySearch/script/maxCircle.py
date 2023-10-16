"""
547. 省份数量
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
返回矩阵中 省份 的数量。
"""


class Solution:
    def findCircleNum(self, isConnected) -> int:
        def dfs(i: int):
            for j in range(cities):
                if isConnected[i][j] == 1 and j not in visited:   # j与i相连，且j不在集合visited
                    visited.add(j)
                    dfs(j)  # 递归，查看是否有其他城市与j属于同一个省份
        
        cities = len(isConnected)
        visited = set()   # 创建集合
        provinces = 0

        for i in range(cities):
            if i not in visited:
                dfs(i)  #
                provinces += 1
        
        return provinces

# Todo:
    #  广度优先搜索(队列)
    #  并查集


if __name__ == '__main__':
    isConnected = [[1,1,0],[1,1,0],[0,0,1]]

    solution = Solution()
    print(solution.findCircleNum(isConnected))

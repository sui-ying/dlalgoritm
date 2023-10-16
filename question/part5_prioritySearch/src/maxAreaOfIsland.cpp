/*
695. 岛屿的最大面积
给你一个大小为 m x n 的二进制矩阵 grid 。
岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
岛屿的面积是岛上值为 1 的单元格的数目。
计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0
*/

#include "../../utils/common.hpp"


class MaxAreaOfisland
{
public:
    vector<vector<int>> grid;
    MaxAreaOfisland(vector<vector<int>> grid){
        this->grid = grid;
    }

    /**
     * 深度优先搜索(depth-first search)
     * 方法一：先判断是否越界，然后递归
     * 
    */
    int dfs(int i, int j){
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1) return 0;
        int area = 1;
        grid[i][j] = 0;  // 防止多搜索
        vector<int> offset = {0, 1, 0, -1, 0}; // {x, y} = {i, i+1}
        for (int ii = 0; ii < 4; ii++){
            area += dfs(i + offset[ii], j + offset[ii + 1]);
        }
        return area;
    }

    /**
     * 深度优先搜索(depth-first search)
     * 方法二：先递归，然后判断是否越界
     * 
    */
    int dfs2(int i, int j){
        if (grid[i][j] == 0) return 0;

        grid[i][j] = 0;  // 防止多搜索
        int area = 1, x, y;
        vector<int> offset = {0, 1, 0, -1, 0}; // {x, y} = {i, i+1}
        for (int ii = 0; ii < 4; ii++){
            x = i + offset[ii], y = j + offset[ii + 1];
            if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size()){
                area += dfs(x, y);
            }
        }
        return area;
    }

    int solution(){
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                maxArea = max(maxArea, dfs2(i, j));
            }
        }

        return maxArea;
    }
};


int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    MaxAreaOfisland maxAreaOfisland(grid);
    cout << maxAreaOfisland.solution() << endl;
    printVector2d(grid);
    
    return 0;
}
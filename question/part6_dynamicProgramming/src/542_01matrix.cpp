/*
542. 01 矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。
*/

#include "../../utils/common.hpp"

/**
 * 两次动态规划求解
 * 
*/
vector<vector<int>> update01Matrix(vector<vector<int>>& mat) {
    if (mat.empty()) return {};
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));  // 1. 定义dp
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {  // 2. 边界条件和迭代公式
                dp[i][j] = 0;
            } else {
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
                if (i > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }
    }

    for (int i = m-1; i > -1; i--) {
        for (int j = n -1; j > -1; j--) {
            if (dp[i][j] != 0) {  // dp[i][j]为0时直接跳过
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
                if (i < m - 1) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
            }
        }
    }
    return dp;
}

int main(){
    vector<vector<int>> matrix = {{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0}};
    vector<vector<int>> res = update01Matrix(matrix);
    printVector2d(res);

    return 0;
}
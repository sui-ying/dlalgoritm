/*

*/

#include "../../utils/common.hpp"

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    if (m == 0 || n == 0) return 0;

    int maxSide = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));  // 构造函数， 赋初始值0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 or j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;  // min（）
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide*maxSide;
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}
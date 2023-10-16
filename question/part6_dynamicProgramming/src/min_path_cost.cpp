#include "../../utils/common.hpp"

/* 实现最小路径损失 */

void printVector2D(const vector<vector<int>>& vec) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        // it 为一个指针， 指向二维向量vec的一级迭代器
        for (auto jt = it->begin(); jt != it->end(); jt++) {
            cout << *jt << " ";
        }
        cout << endl;
    }

    // for (vector<vector<int>>::iterator it = dp.begin(); it != dp.end(); it++){
    //     for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++){
    //         cout << *jt << " ";
    //     }
    //     cout << endl;
    // }
}

/**
 * @brief 
 * @param grid 
 * @return int 
 */
int min_path_cos(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp = {m, vector<int>(n, 0)};
    dp[0][0] = grid[0][0];
    for (int i=1; i<m; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0]; 
    }
    for (int j=1; j<n; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j]; 
    }
    // printVector2D(dp);
    for (int i=1; i<m; i++){
        for (int j=1; j<n; j++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}

int main(){
    vector<vector<int>>grid = {{1, 3, 1, 5}, {2, 2, 4, 2}, {5, 3, 2, 1}, {4, 3, 5, 2}};
    // printVector2D(grid);
    cout << min_path_cos(grid) << endl;
    return 0;
}
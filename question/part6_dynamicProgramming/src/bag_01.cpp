#include "../../utils/common.hpp"

// int knapsack_dp(vector<int> wgt, vector<int> val, int cap) {
    // int m = val.size();
    // int n = wgt.size();
    // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // for (int i = 1; i < m + 1 ; i++) {
    //     for (int j = 1; j < n + 1; j++) {
    //         if (wgt[i - 1] >= cap) {  // 若超过背包容量，则不选物品 i
    //             dp[i][j] = dp[i - 1][j];
    //         } else {  //  # 不选和选物品 i 这两种方案的较大值
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wgt[i - 1]] + val[i - 1]);
    //         }
    //     }
    // }
    // printVector2d(dp);
// }

int knapsack(vector<int> weights, vector<int> values, int N, int bagWeight) {
    vector<vector<int>> dp(N + 1, vector<int>(bagWeight + 1, 0));
    for (int i = 1; i <= N; ++i) {
        int w = weights[i-1], v = values[i-1];
        for (int j = 1; j <= bagWeight; ++j) {
            if (j >= w) {  // 将物品 i 放入背包
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
            } else {   // 不将物品 i 放入背包
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printVector2d(dp);
    return dp[N][bagWeight];
}

int main(){
    // vector<int> wgt = {10, 20, 30, 40, 50};
    // vector<int> val = {50, 120, 150, 210, 20};
    vector<int> wgt = {2, 3, 4};
    vector<int> val = {2, 3, 4};
    int N = 3;
    int bagWeight = 5;
    cout << knapsack(wgt, val, N, bagWeight) << endl;
    return 0;
}

/* 现有2元、3元、5元共三种面额的货币, 如果需要找零99元, 一共有多少种找零的方式 */

#include<iostream>
#include<vector>

using namespace std;

// dp = [float('inf')] * (amount + 1)  # 表示组成金额 i 所需的最少硬币数
//     dp[0] = 0

//     # for i in range(1, amount + 1):
//     #     for coin in coins:
//     #         if i >= coin:
//     #             dp[i] = min(dp[i], dp[i - coin] + 1)

//     for coin in coins:
//         for i in range(1, amount + 1):
//             if i >= coin:
//                 dp[i] = min(dp[i], dp[i - coin] + 1)

//     if dp[amount] == float('inf'):
//         return -1
//     else:
//         return dp[amount]

int minCoinChange(int amount, vector<int>& coins){
    int Max = amount + 1;
    vector<int>dp(amount+1, Max);  // 构造函数将amount个Max拷贝给dp
    dp[0]=0; // 初始值
    for (int i=1; i<=amount; i++){
        for (int j=0; j<coins.size(); j++){
            if (i >= coins[j]){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    // for (vector<int>::iterator it = dp.begin(); it != dp.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;
    return dp[amount] >= Max ? -1: dp[amount];
}



int main(){
    int amount = 99;
    vector<int>coins = {2, 3, 5};
    int num_coins = minCoinChange(amount, coins);
    cout << "num_coins: " << num_coins << endl;
    return 0;
}
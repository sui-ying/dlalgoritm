/*

*/

#include "../../utils/common.hpp"


int numSquares(int num) {
    vector<int>dp(num + 1);
    // for (int i = 0; i < num + 1; i++) {
    //     dp.push_back(i);
    // }
    iota(dp.begin(), dp.end(), 0);  // 从 0 开始递增的整数填充到 dp 向量中
    printVector(dp);   
    
    for (int i = 2; i < num + 1; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[num];
}

int main(){
    int num = 12;
    cout << numSquares(num) << endl;
    return 0;
}
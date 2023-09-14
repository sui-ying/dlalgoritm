#include "../../utils/common.hpp"

/* 给定一个共有 $n$ 阶的楼梯，你每步可以上 $1$ 阶或者 $2$ 阶，请问有多少种方案可以爬到楼顶 */

/**
 * @brief 动态规划: 从前往后递推
 * @param n 
 * @return int 
 */
int climb_stairs(int n){
    if (n==1 or n==2){
        return n;
    }

    vector<int>dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;  // dp[i] = j 表示爬n阶梯子总共的方法
    
    for (int i=3; i<n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    // for (const auto& element : dp) {
    //     std::cout << element << " ";
    // }
    // cout << endl;

    return dp[n];
}

/**
 * @brief 滚动变量求解: 空间优化后的动态规划
 * @param n 
 * @return int 
 */
int climb_stairs_plus(int n){
    if (n==1 or n==2){
        return n;
    }
    int a=1;
    int b=2;
    for (int i=3; i<n+1; i++){
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}

/*
加以限制:
给定一个共有 $n$ 阶的楼梯，你每步可以上 $1$ 阶或者 $2$ 阶，**但不能连续两轮跳 $1$ 阶**，请问有多少种方案可以爬到楼顶。
*/
int climb_stairs_constraint(int n){
    if (n==1 or n==2){
        return 1;
    }

    // 状态 dp[i][j] 表示处在第 i 阶、并且上一轮跳了 j(1 or 2) 阶
    vector<vector<int>>dp(n+1, vector<int>(3, 0));  // 定义二维vector
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for (int i=3; i<n+1; i++){
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    }
    
    return dp[n][1] + dp[n][2];
}


int main(){
    cout << climb_stairs(10) << endl;
    cout << climb_stairs_plus(10) << endl;

    cout << climb_stairs_constraint(10) << endl;
    return 0;
}

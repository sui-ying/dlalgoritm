/*
139. 单词拆分
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
*/

#include "../../utils/common.hpp"


bool wordBreak(string& s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool>dp(n, false);   // 1. 定义dp, dp[i]表示s 的前 i 位是否可以用 wordDict中的单词表示; 
    dp[0] = true;  // 初始条件
    
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < i; j++) {
            // find 函数查找vector中是否存在待查找元素，返回一个迭代器，如果不等于vector.end()表示待查找元素在vector中
            if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end() ) {
                dp[i] = true;
                break;
            }
        } 
    }

    return dp[n];
}

int main(){
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}
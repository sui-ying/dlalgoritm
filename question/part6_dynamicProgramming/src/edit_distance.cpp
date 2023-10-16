#include "../../utils/common.hpp"

void printVector2D(const vector<vector<int>>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        // it 为一个指针， 指向二维向量vec的一级迭代器
        for (auto jt = it->begin(); jt != it->end(); ++jt) {
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


int edit_distance(string s1, string s2){
    if (s1.size() == 0){
        return s2.size();
    }
    if (s2.size() == 0){
        return s1.size();
    }

    vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for (int i=0; i<s1.size()+1; i++){
        dp[i][0] = i;
    }
    for (int j=0; j<s2.size()+1; j++){
        dp[0][j] = j;
    }

    for (int i=1; i<s1.size()+1; i++){
        for (int j=1; j<s2.size()+1; j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }  
    return dp[s1.size()][s2.size()];
}

int main(){
    cout << edit_distance("bag", "pack") << endl; 
    return 0;
}
/*
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
*/

#include "../../utils/common.hpp"

int NOI( vector<vector<int>>& arr2d){
    int length = arr2d.size();   // 向量的长度可以通过其size()成员函数来获取
    int res = 0;
    int preNode = arr2d[0][1];
    for (int i = 1; i < length; i++){
        if (arr2d[i][0] < preNode){
            res += 1;
        }
        else{
            preNode = arr2d[i][1];
        }
    }
    
    return res;
}

int main(){
    vector<vector<int>>arr2d = {{1, 2}, {2, 4}, {1, 3}};
    cout << NOI(arr2d) << endl;
    return 0;
}
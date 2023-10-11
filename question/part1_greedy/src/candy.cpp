/*
一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是
如果一个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所有孩子至少要有一个糖果。
求解最少需要多少个糖果。
*/

#include "../../utils/common.hpp"

int candy(vector<int>& arr){
    int length = arr.size();   // 向量的长度可以通过其size()成员函数来获取
    cout << "length: " <<  length << endl;
    vector<int> res(length, 1);  //  赋值方式
    for (int i = 1; i < length; i++){
        if (arr[i] > arr[i-1]){
            res[i] += 1;
        }
    }
    for (int j=length-2; j > -1; j--){
        if (arr[j] > arr[j+1]){
            res[j] += 1;
        }
    }
    
    return sumVector(res);
}

int main(){
    vector<int>arr = {1, 0, 2};
    printVector(arr);
    cout << candy(arr) << endl;
    return 0;
}
#pragma once

#include<iostream>
#include<vector>
using namespace std;

/**
 * 打印一维vector
 * 如需打印其他C++中数据类型，可以将函数改写成模板函数
*/
void printVector(vector<int>& arr){
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


int sumVector(vector<int>& arr){
    int result = 0;
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
        result += *it;
    }
    return result;
}
    
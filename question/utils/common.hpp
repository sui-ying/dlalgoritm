#pragma once

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
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

/**
 * 打印unordered_map，输出形式类似python中的字典    
*/
void printUnorderedMap(unordered_map<char, int>& um){
    for (const auto& pair : um) {
        cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    cout << endl;
}
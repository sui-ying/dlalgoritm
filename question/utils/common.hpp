#pragma once

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>

#include<numeric>

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

/**
 * 打印二维vector
 * 如需打印其他C++中数据类型，可以将函数改写成模板函数
*/
void printVector2d(vector<vector<int>>& arr2d){
    for (vector<vector<int>>::iterator it = arr2d.begin(); it != arr2d.end(); it++){ // it 为一个指针， 指向二维向量vec的一级迭代器
        for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++){
            cout << *jt << " ";
        }
        cout << endl;
    }

    // for (auto it = arr2d.begin(); it != arr2d.end(); ++it) {
    //     // it 为一个指针， 指向二维向量vec的一级迭代器
    //     for (auto jt = it->begin(); jt != it->end(); ++jt) {
    //         cout << *jt << " ";
    //     }
    //     cout << endl;
    // }
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
/* 写一个删除列表中重复元素的函数，要求去重后元素相对位置保持不变 */
// 也可以通过链表实现上述功能 

#include<iostream>
#include<vector>
#include<set>
using namespace std;


void printVector(vector<float>& v){
    for (vector<float>::iterator it=v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void delete_repeat_elem(vector<float>& v){
    set<float>s;      // local variable: 在函数结束后会自动销毁，不会造成内存泄漏
    vector<float>v1;  // local variable: 
    for (vector<float>::iterator it=v.begin(); it != v.end(); it++){
        set<float>::iterator pos = s.find(*it);
        if (pos == s.end()){
            // cout << "not find elem" << endl;
            s.insert(*it);
            v1.push_back(*it);
        }
    }
    v.swap(v1);  // v swap v1
}

int main(){
    vector<float>v={1, 2, 4, 3, 5, 3, 4, 2, 1};  // 定义vector同时对其进行初始化: float 为四字节
    printVector(v);
    delete_repeat_elem(v);
    printVector(v);
    return 0;
}
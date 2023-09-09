/* 写一个函数统计传入的列表中每个数字出现的次数并返回对应的字典 */

#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>
using namespace std;

void printVector(vector<int>& v){
    for (vector<int>::iterator it=v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printMap(map<int, int>& m){
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
        cout << "key: " << (*it).first << "\t value: " <<(*it).second << endl;
    }
}

map<int, int> count_nums(vector<int>& v1){
    map<int, int>m;
    for (vector<int>::iterator it=v1.begin(); it != v1.end(); it++){
        map<int, int>::iterator pos = m.find(*it);
        if (pos != m.end()){
            pos->second++;
            // cout << "find key-value: " << (*pos).first << " " << pos->second << endl;
        }
        else{
            // cout << "not find elem: " << *it << endl;
            m.insert(pair<int, int>(*it, 1));
        }
    }
    return m;
}

unordered_map<int, int> countNumbers(const vector<int>& nums) {
    unordered_map<int, int> countMap;
    for (const auto& num : nums) {
        countMap[num]++;
    }
    return countMap;
}

int main(){
    vector<int>nums = {1, 2, 3, 2, 1, 4};
    printVector(nums);
    map<int, int>m = count_nums(nums); // 有序的
    printMap(m);

    // 2
    unordered_map<int, int>um = countNumbers(nums);  // 无序的
    for (const auto& pair : um) {
        std::cout << "Number: " << pair.first << "\t Count: " << pair.second << std::endl;
    }
    return 0;
}
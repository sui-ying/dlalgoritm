/*
524. 通过删除字母匹配到字典里最长单词
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
tips: 默认有顺序
*/

#include "../../utils/common.hpp"

/**
 *  1. dictionary中的每一个字符串t与s进行比较: 使用双指针(一个指向s开始，一个指向t开始)，从左向右偏移，对比，是否能够到达最后一个t的末尾
 *  2. 取字符串中最长的，字母序最小
*/
string findLongestWord(string& s, vector<string>& dictionary){
    string res;
    for (const auto& t: dictionary){
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()){
            if (s[i] == t[j]){
                j++;
            }
            i++;
        }

        if (j == t.size()) {
            if (t.size() > res.size() || (t.size() == res.size() && t < res)){   // t < res 比对两个字符串的字母序
                res = t;
            }
        }
    }
    return res;
}

// def findLongestWordPlus(s: str, dictionary: list) -> str:
//     """
//     预先对dictionary按照长度从大到小，字母序进行排序
//     1. dictionary中的每一个字符串t与s进行比较: 使用双指针(一个指向s开始，一个指向t开始)，从左向右偏移，对比，是否能够到达最后一个t的末尾
//         2. 能达到，则是最小的
//     """

//     dictionary.sort(key=lambda x: (-len(x), x))
//     for t in dictionary:
//         i, j = 0, 0
//         while i<len(s) and j<len(t):
//             if s[i] == t[j]:
//                 j += 1
//             i += 1

//         if j == len(t):
//             return t
//     return ""


// Todo: 动态规划求解

int main(){
    string s = "abpcplea";
    vector<string> dictionary = {"ale","apple","monkey","plea"};
    cout << findLongestWord(s, dictionary) << endl;
    // print(findLongestWordPlus(s, dictionary))
}
    
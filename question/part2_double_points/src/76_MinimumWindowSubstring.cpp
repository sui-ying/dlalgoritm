/*
76
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
*/

#include "../../utils/common.hpp"


class MinimumWindowSubstring {
public:
    string s, t;
    MinimumWindowSubstring(string s, string t): s(s), t(t){}

    void printString() {
        cout << s << " " << t << endl;
    }

    unordered_map <char, int> ori, cnt;

    /**
     * 检查当前记录下来的字符出现次数是否涵盖了字符串 t 中所有字符的出现次数
    */
    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    /**
     * 通过滑动区间(l, r)(双指针)遍历待搜索字符串s找到粗略区间，同时维护unordered_map cnt, 逐渐缩小区间直到找到最小的区间
    */    
    string minWindow() {
        for (const auto &c: t) {
            ++ori[c];  // 更新unordered_map <char, int> ori， 将目标字符串转换为unordered_map形式
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1;  // INT_MAX是一个常量，表示整型变量（int）所能表示的最大值

        while (r < int(s.size())) {  // 从左向右遍历待搜索字符串s
            if (ori.find(s[++r]) != ori.end()) {  // 字符串查找，如果不是最后一个字符串; 同时变量r自增1，即区间右边r移动
                ++cnt[s[r]];  // 通过区间右边向右移动更新unordered_map <char, int> cnt
            }
            
            while (check() && l <= r) {  //  
                if (r - l + 1 < len) {  // 定区间：更新最小区间大小，同记录区间起始位置
                    len = r - l + 1;  
                    ansL = l;
                }
                // cout << l << " " << r << " " << len << " " << s.substr(l, len) << endl;
                if (ori.find(s[l]) != ori.end()) {  // 缩小区间s.substr(l, len), 更新unordered_map cnt, 直到包含目标字符串的最小区间
                    --cnt[s[l]];  // 通过区间左边向右移动更新unordered_map cnt
                }
                ++l;  // 进一步缩小区间, l向右偏移
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    MinimumWindowSubstring mws(s, t);
    mws.printString();
    cout << mws.minWindow() << endl;
    return 0;
}

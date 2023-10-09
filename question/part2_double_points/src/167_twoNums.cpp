/*
167
在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
*/

#include "../../utils/common.hpp"

vector<int> twoNums(vector<int>& nums, int target){
    int length = nums.size();
    int l= 0; 
    int r = length-1; 
    while (l<r){
        int total  = nums[l] + nums[r];
        if (total == target){
            return vector<int>{l+1, r+1};
        }
        else if (total < target){
            l++;
        }
        else{
            r--;
        }
    }
    return vector<int>{-1, -1};
}

/*
633. 平方数之和
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
*/
bool judgeSquareSum(int target){
    int l=0, r=sqrt(target);
    while (l<=r){
        int res = l*l + r*r;
        if (res==target){
            return true;
        }
        else if(res > target){
            r -= 1;
        }
        else{
            l += 1;
        }
    }
    return false;
}

class vP
{
public:
    string s;
    vP(string s): s(s) {}

    bool isValidPalindrome(int l, int r){
        while (l<r){
            if (s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }

    bool validPalindrome() {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]){
                l++;
                r--;
            } else {
                return isValidPalindrome(l, r-1) || isValidPalindrome(l+1, r);
            }
        }
        return true;
    }

};


int main(){
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>res = twoNums(nums, target);
    printVector(res);

    cout << judgeSquareSum(target) << endl;
    
    vP vp("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
    cout << vp.validPalindrome() << endl;

    return 0;
}

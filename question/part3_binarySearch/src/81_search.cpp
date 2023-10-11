/*

*/

#include "../../utils/common.hpp"


/*
154. 寻找旋转排序数组中的最小值 II
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
你必须尽可能减少整个过程的操作步骤。
*/


int search(vector<int>& nums){
    int l = 0, r = nums.size()-1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[r]) {  // 中值大于右值时，最小值肯定在右半部分，
            l = mid + 1;
        } else if (nums[mid] < nums[r]) {  // 中值小于右值是，右半部分有序，最小值肯定在左半部分
            r = mid;
        } else {  // 中值和右值相等时，r--
            r--;
        } 
    }
    return nums[l];
}

int main(){
    vector<int> nums = {3, 3, 1, 3};
    int target = 5;
    cout << search(nums) << endl;
    return 0;
}
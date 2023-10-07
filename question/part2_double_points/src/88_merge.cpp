/*
88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
*/

#include "../../utils/common.hpp"

/**
 * 从后往前遍历，每次将两个数组中末尾数较大的那一个赋给nums1的最后一个位置，依次向前填充
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m-1;
    int p2 = n-1;
    int p = m+n-1;
    while (p1>=0 || p2>=0){
        if (p1 == -1){
            // ++ 和--的小技巧：a++ 和 ++a 都是将 a 加 1，
            // 但是 a++ 返回值为 a，
            // 而++a 返回值为 a+1。如果只是希望增加 a 的值，而不需要返回值，则推荐使用a++ or a--其运行速度会略快一些。
            nums1[p--] = nums2[p2--];   
        }
        else if(p2 == -1){
            nums1[p--] = nums1[p1--];
            // break;
        }
        else if (nums1[p1] >= nums2[p2]){
            nums1[p--] = nums1[p1--];
        }
        else{
            nums1[p--] = nums2[p2--];
        }
    }
}

int main(){
    vector<int>nums1 = {2,7,11,15, 0, 0, 0};
    int m = 4;
    vector<int>nums2 = {2,5,8};
    int n = 3;
    merge(nums1, m, nums2, n);
    printVector(nums1);
    return 0;
}


/*
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。
*/

#include "../../utils/common.hpp"

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();

        // 特殊情况
        if (n==0){
           return true;
        }
        if (length==1 && flowerbed[0] == 0){
            return 1>=n;
        }
                
        for(int i=0; i<length; i++){
            if (i==0){
                if (flowerbed[0] == 0 && flowerbed[1] == 0){
                    flowerbed[0] = 1;
                    n--;
                    if (n==0){
                        return true;
                    }
                }
                
            }
            else if (i==length-1){
                if (flowerbed[i] == 0 && flowerbed[i-1] == 0){
                    flowerbed[i] = 1;
                    n--;
                    if (n==0){
                        return true;
                    }
                }
            } 
            else{
                if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    n--;
                    if (n==0){
                        return true;
                    }
                }
            }
        }
        return false;
    }

class Solution
{
public:
    vector<int>arr;
    int n;
    Solution(vector<int>&arr, int n){
        this->arr = arr;
        this->n = n;
    }

    bool canPlaceFlowers(){
        int length = this->arr.size();
        vector<int>flower = this->arr;
       
        if (n == 0){
            return true;
        }
        if (length == 1 && flower[0] == 0){
            return 1>=n;
        }

        for(int i=0; i<length; i++){
            if(i==0){
                if(flower[i]==0 && flower[i+1] == 0){
                    flower[0] = 1;
                    this->n--;
                    if (this->n == 0){
                        return true;
                    }
                }
            }
            else if (i==length-1) {
                if (flower[i] == 0 && flower[i-1] == 0) {
                    flower[i] = 1;
                    this->n--;
                    if (this->n == 0){
                        return true;
                    }
                }
            }
            else{
                if (flower[i] == 0 && flower[i-1] == 0 && flower[i-1] == 0 && flower[i+1] == 0) {
                    flower[i] = 1;
                    this->n--;
                    if (this->n == 0){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool canPlaceFlowersPlus(){
        int length = this->arr.size();
        int pre = -1;
        int count = 0;

        for(int i=0; i<length; i++){
            if (this->arr[i] == 1){
                if (pre < 0){
                    count += i/2;
                }
                else{
                    count += (i - pre - 2) / 2;
                }
                if (count > n){
                    return true;
                }
                pre = i;
            }
        }

        if (pre < 0){
            count += (length + 1)/2;
        }
        else{
            count += (length - pre -1)/2;
        }
        return count >= n;
    }

};


int main(){
    vector<int>arr = {0,0,1,0,1};
    int n = 1;
    // cout << canPlaceFlowers(arr, n) << endl;
    // printVector(arr);
    Solution solution(arr, n);
    cout << solution.canPlaceFlowers() << endl;
    cout << solution.canPlaceFlowersPlus() << endl;
    return 0;
}
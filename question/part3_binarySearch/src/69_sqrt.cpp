/*
69. x 的平方根
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
*/

#include "../../utils/common.hpp"


int sqrtBinarySearch(int& x){
    int l=0, r=x, res=-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (mid*mid - x <= 0) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int sqrtTaylor(int& x){
    if (x == 0){
        return 0;
    }

    double C=x, x0=x;
    while (true) {
        double x1 = 0.5 * (x0 + C/x0);
        if (abs(x0-x1) < 1e-7){
            break;
        }
        x0 = x1;
    }
    return int(x0);
}


int main(){
    int num = 8;
    cout << sqrtBinarySearch(num) << endl;
    cout << sqrtTaylor(num) << endl;
    return 0;
}
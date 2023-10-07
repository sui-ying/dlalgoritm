/*
有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，
其中points{i} = {xstart, xend} 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
*/

#include "../../utils/common.hpp"

int findMinArrowShots( vector<vector<int>>& arr2d){
    int length = arr2d.size();
    if (length <= 1){
        return length;
    }

    sort(arr2d.begin(), arr2d.end(), [](vector<int> a, vector<int> b) 
        { return a[1] < b[1]; }
    );  //升序排序
    
    int res = 1;
    int pre = arr2d[0][1];
    for (int i=1; i<length; i++){
        if (arr2d[i][0] > pre){
            res++;
            pre = arr2d[i][1];
        }
    }

    return res;
}

int main(){
    vector<vector<int>>arr2d = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    cout << findMinArrowShots(arr2d) << endl;
    return 0;
}
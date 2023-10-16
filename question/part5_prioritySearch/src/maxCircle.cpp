/*
547. 省份数量
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
给你一个 n x n 的矩阵 isConnected ，其中 isConnected{i}{j} = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected{i}{j} = 0 表示二者不直接相连。
返回矩阵中 省份 的数量。
*/

#include "../../utils/common.hpp"

/**
 * 深度搜索算法
 * 通过vector和set容器进行编写代码，运算效率不高
*/
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, set<int>& visited, int i){
        for (int j = 0; j < isConnected.size(); j++) {
            if ( isConnected[i][j] == 1 && visited.find(j) == visited.end() ) {  // # 找到与i相连的城市: j与i相连，且j不在集合visited
                visited.insert(j);
                dfs(isConnected, visited, j);  // 深度优先搜索：递归，查看是否有其他与已经相连城市j属于同一个省份的城市
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        set<int> visited;
        int provinces = 0;
        
        for (int i = 0; i < isConnected.size(); i++){
            if (visited.find(i) == visited.end()){   // find到结束没有找到城市i, 城市i不在visited中
                dfs(isConnected, visited, i);  // 深度优先搜索
                provinces++;
            }
        }
        return provinces;
    }
};


/**
 * 深度搜索算法
 * 只通过vector容器进行编写代码，运算效率不及Solution1
*/
class Solution2 {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int i){
        for (int j = 0; j < isConnected.size(); j++) {
            if ( isConnected[i][j] == 1 && !visited[j]) {  // # j与i相连，且j不在集合visited
                visited[j] = 1;
                dfs(isConnected, visited, j);  // 递归，查看是否有其他城市与j属于同一个省份
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size());   // 初始化访问城市为全0，表示所有城市还未搜索
        // printVector(visited);
        int provinces = 0;
        
        for (int i = 0; i < isConnected.size(); i++){
            if (!visited[i]){   // find到结束没有找到城市i, 城市i不在visited中
                dfs(isConnected, visited, i);  // 深度优先搜索
                provinces++;
            }
        }
        return provinces;
    }
};


int main(){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    
    Solution solution;
    cout << solution.findCircleNum(isConnected) << endl;

    Solution2 solution2;
    cout << solution2.findCircleNum(isConnected) << endl;

    return 0;
}
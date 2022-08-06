/*
https://leetcode.com/problems/number-of-provinces/
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
*/

class Solution {
    //DFS Solution, Time Complexity of O(V^2), Space Complexity of O(V)
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()){
            return 0;
        }
        
        vector<bool> visited(isConnected.size(), false);
        int res = 0;
        
        for(int i=0; i < isConnected.size(); i++){
            //res++ for every unvisited node (a same group of node will be marked as visited by DFS already)
            if(!visited[i]){
                dfs(isConnected, visited, i);
                res++;
            }
        }
        return res;
        
        
    }
    
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            //keep track to the end of the group (continue DFS if there is another unvisited node connected)
            if (i != j && isConnected[i][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }
};

//Alternative solution: Union Find
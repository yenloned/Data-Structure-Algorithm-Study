/*
https://leetcode.com/problems/max-area-of-island/
You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.
*/


//For this question, it is very similar with 200 NumberOfIslands.cpp, but creating 2 global counters instead
//For the comment explanation, please see 200 NumberOfIslands.cpp.
//Also there will be DFS and BFS Solution
class Solution {
    //DFS Graph Solution, Time Complexity of O(r*c) / O(v), Space Complexity of O(v)
    //r = rows, c = columns, v = nodes/vertices
private:
    int maxSize = 0;
    int curSize = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                curSize = 0;
                if(grid[i][j] == 1){
                    dfs(grid, i ,j);
                    maxSize = max(maxSize, curSize++);
                }
            }
        }
        return maxSize;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return;
        }
        maxSize = max(maxSize, curSize++);
        grid[i][j] = 0;
        
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

//===================================== Second Solution ======================================
class Solution {
    //BFS Graph Solution, Time Complexity of O(r*c) / O(v), Space Complexity of O(v)
    //r = rows, c = columns, v = nodes/vertices
private:
    int maxSize = 0;
    int curSize = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                curSize = 0;
                if(grid[i][j] == 1){
                    bfs(grid, i, j);
                    maxSize = max(maxSize, curSize++);
                }
            }
        }
        return maxSize;
    }
    
    void bfs(vector<vector<int>>& grid, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            maxSize = max(maxSize, curSize++);
            q.pop();
            
            if (i < grid.size() - 1 && grid[i+1][j] == 1){
                q.push({i+1, j});
                grid[i+1][j] = 0;
            }
            if (i > 0  && grid[i-1][j] == 1){
                q.push({i-1, j});
                grid[i-1][j] = 0;
            }
            if (j < grid[0].size() - 1 && grid[i][j+1] == 1){
                q.push({i, j+1});
                grid[i][j+1] = 0;
            }
            if (j > 0 && grid[i][j-1] == 1){
                q.push({i, j-1});
                grid[i][j-1] = 0;
            }
        }
        
    }
};
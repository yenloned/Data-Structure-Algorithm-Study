/*
https://leetcode.com/problems/number-of-islands/
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/

//For this question, there will be DFS / BFS solutions, it is suggested to know both.

class Solution {
    //DFS Graph Solution, Time Complexity of O(r*c) / O(v), Space Complexity of O(v)
    //r = rows, c = columns, v = nodes/vertices
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int res = 0;
        //Scan every nodes/vertices in the graph, which is a 2D array
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){          //Once we found the first land, we could start DFS for any other connect lands.
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        //Base Case for DFS recursion, note that we should put grid[i][j] in the last check since it might have unsigned error with negative index
        //index range / if that spot is visited / water
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0'){
            return;
        }
        //marking the current land as "visited", marking it as '0' so it can be checked with the same condition of water
        grid[i][j] = '0';
        
        //Recursion checking DFS with 4direction (right, down, left, up)
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
    }
};

//=============================================== Second Solution ===============================================

class Solution {
    //BFS Graph Solution, Time Complexity of O(r*c) / O(v), Space Complexity of O(v)
    //r = rows, c = columns, v = nodes/vertices
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int res = 0;
        //Scan every nodes/vertices in the graph, which is a 2D array
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){          //Once we found the first land, we could start DFS for any other connect lands.
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int, int>> q;    //Because of BFS, we will use of a queue
        q.push({i, j});
        grid[i][j] = '0';   //First, mark the current spot as "visited"
        
        //Iterative approach for BFS
        while(!q.empty()){
            i = q.front().first;    //i become the current checking row
            j = q.front().second;   //j become the current checking column
            q.pop();
            
            //Check each direction, the spot will be pushed into the queue for the next loop to check more adjacent spots
            if (i < grid.size() - 1 && grid[i+1][j] == '1'){
                q.push({i+1, j});
                grid[i+1][j] = '0';
            }
            if (i > 0  && grid[i-1][j] == '1'){
                q.push({i-1, j});
                grid[i-1][j] = '0';
            }
            if (j < grid[0].size() - 1 && grid[i][j+1] == '1'){
                q.push({i, j+1});
                grid[i][j+1] = '0';
            }
            if (j > 0 && grid[i][j-1] == '1'){
                q.push({i, j-1});
                grid[i][j-1] = '0';
            }
        }
        
    }
};
/*
https://leetcode.com/problems/rotting-oranges/
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

class Solution {
    //BFS Graph Solution, Time Complexity of O(r*c) / O(v), Space Complexity of O(v)
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        //Scan every nodes/vertices in the graph
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});         //push every rotten spot in first 0 minute to start with
                } else if (grid[i][j] == 1) {
                    fresh++;                //count how many fresh orange to determine if it is impossible in the end
                }
            }
        }
        
        //push a invalid(unexpected) pair for counting minute
        q.push({-1, -1});
        //because we need to start the count at 0, -1 will be initialized instead
        int result = -1;
        //direction array
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        //Perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //increment the minute count once we encounter the counter
            if (row == -1 && col == -1) {
                result++;
                //insert the counter for the orange set in each minute
                //only insert the counter when only the counter is met and there is oranges in queue, this way could ensure the counter will only be incremented EACH MINUTE
                if (!q.empty()) {
                    q.push({-1, -1});
                }
            } else {
                //BFS for four direction
                for (int i = 0; i < dirs.size(); i++) {
                    int x = row + dirs[i][0];
                    int y = col + dirs[i][1];
                    
                    //Base case if the position is out of range
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    
                    //Rotten the adjacency oranges and push them into queue for BFS checking
                    if (grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
        }
        
        //If there is still fresh orange, it means it is impossible to rotten them
        if (fresh == 0) {
            return result;
        }
        return -1;
    }
};
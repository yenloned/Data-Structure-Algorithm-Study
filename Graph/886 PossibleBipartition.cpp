/*
https://leetcode.com/problems/possible-bipartition/
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

Example:
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
*/

class Solution {
    //DFS Coloring Solution, Time Complexity of O(n+m), Space Complexity of O(m)
    //where n is n, m is the number of all dislikes
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        
        //indicate which person can not group with which person
        for(auto &d : dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        
        vector<int> color(n+1,0);
        vector<int> visited(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                color[i] = 1;
                if(!dfs(adj,visited,color,i))
                    return false;
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>> &adj,vector<int> &visited,vector<int> &color,int node){
        //visit current person
        visited[node] = 1;
        for(auto v : adj[node]){
            //if the disliked person has not been visited
            if(!visited[v]){
                //switch the color of all disliked person to the opposite color of the current person
                //the next time to perform this action will change back to 1 (3-1 = 2 / 3-2 = 1)
                color[v] = 3-color[node];
                //start dfs with disliked person
                if(!dfs(adj,visited,color,v))
                    return false;
            }
            //if they are in the same color (same group)
            else if(color[v]==color[node])
                return false;
        }   
        return true;
    }
};
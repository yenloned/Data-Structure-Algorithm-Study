/*
https://leetcode.com/problems/all-paths-from-source-to-target/
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example:
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/

class Solution {
    //DFS Solution, Time Complexity of O(E), Space Complexity of O(N)
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> path;           //temp array for possible path
        vector<vector<int>> ans;    //all possible paths
        dfs(graph, ans, path, 0);
       
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph,  vector<vector<int>>& ans, vector<int>& path, int node){
        path.push_back(node);       //push the current node
        
        //if the current node is the destination, push the path we added up into all possible path
        if(node == graph.size()-1){
            ans.push_back(path);
        //if not, start dfs for all the next nodes
        }else{
            for(int i=0; i<graph[node].size(); i++){
                dfs(graph, ans, path, graph[node][i]);
            }
        }
        //pop out the pushed element AFTER DFS
        //it is important to understand the concept of recursion stack in this step!!!
        path.pop_back();
    }
};
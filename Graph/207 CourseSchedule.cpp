/*
https://leetcode.com/problems/course-schedule/
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

**NOTE that 0 <= ai, bi < numCourses**
*/

class Solution {
    //Kahn's Algorithm Solution, Time Complexity of O(V+E), Space Complexity of O(V)
    /*Reference: 
    Kahn's Algorithm: https://www.youtube.com/watch?v=cIBFEhD77b4&ab_channel=WilliamFiset
    Topological Sort Algorithm: https://www.youtube.com/watch?v=eL-KzMXSXXI&ab_channel=WilliamFiset
    */
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Create two vectors with size of numCourses and default empty value (0 or empty vector)
        vector<vector<int>> adj(numCourses, vector<int>());     //indicate what nodes depended by
        vector<int> degree(numCourses, 0);                      //indicate how many nodes are depended on
        
        //First mark how many dependencies (edges) pointing at every possible node (0 - numCourses)
        //We only need to walk every nodes since the unmarked nodes (no dependencies) will be default 0
        for (auto &p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        
        //Then, first we put all the unmarked nodes into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (degree[i] == 0){
                q.push(i);
            }
        
        //In this loop, every node pushed into queue is the nodes that has no dependency (no more pre-courses)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            numCourses--;
            //Pushing the nodes which has no more dependency (value = 0 in degree vector)
            for (auto next: adj[curr]){
                //--degree[next] to remove the node from the graph (no longer needed to check)
                //It has no more dependency when it has value 0 in degree
                if (--degree[next] == 0){
                    q.push(next);
                }
            }
        }
        //Since we decrement the numCourse for every time a node got no more dependency,
        //we can simply check if there is any nodes have dependency.
        return numCourses == 0;
    }
};
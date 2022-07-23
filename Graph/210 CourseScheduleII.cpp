/*
https://leetcode.com/problems/course-schedule-ii/
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
*/

class Solution {
    //Kahn's Algorithm Solution, Time Complexity of O(V+E), Space Complexity of O(V)
    //For this question, it is very similar to 207 CourseSchedule.cpp, please check it out to spot the difference ( vector<int> res; )
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        vector<int> res;
        
        for (auto &p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (degree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            numCourses--;
            for (auto next: adj[curr])
                if (--degree[next] == 0){
                    q.push(next);
                    res.push_back(next);
                }
        }
        if(numCourses == 0){
            return res;
        }
        return vector<int>();
    }
};
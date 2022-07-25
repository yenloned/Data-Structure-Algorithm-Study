/*
https://leetcode.com/problems/redundant-connection/
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Example:
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
*/

class Solution {
    /*
    Union Find (w/ path compression) Solution, Time Complexity of O(n), Space Complexity of O(n)
    Reference:
    https://www.youtube.com/watch?v=ibjEGG7ylHk&ab_channel=WilliamFiset
    https://www.youtube.com/watch?v=0jNmHPfA_yE&ab_channel=WilliamFiset
    https://www.youtube.com/watch?v=VHRhJWacxis&ab_channel=WilliamFiset
    */
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        //initiate the parents vector, every node's parent will be itself in first iteration
        vector<int> parents;
        for (int i = 0; i < n + 1; i++) {
            parents.push_back(i);
        }
        
        //check every pair to see if they are in the same union/group.
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            //It indicated "redundant" connection if they are in the same union/group.
            if (!Union(parents, n1, n2)) {
                result = {n1, n2};
                break;
            }
        }
        return result;
    }

    //Check what is the parent of that node
    int find(vector<int>& parents, int n) {
        int p = parents[n];
        while (p != parents[p]) {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }
    
    //Check if the pair is in the same union/group by finding/comparing their parent
    bool Union(vector<int>& parents, int n1, int n2) {
        int p1 = find(parents, n1);
        int p2 = find(parents, n2);
        if (p1 == p2) {
            return false;
        }
        //If they have different union, marge them as one (assign one node as another node's parent)
        //In original Union Find Algorithm, "ranks" vector should be used to determine which node be the parent
        //But it does not matter in this situation since we only focus on checking if the pair has the same parent (same union)
        parents[p2] = p1;   //or parents[p1] = p2;
        return true;
    }
};
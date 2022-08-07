/*
https://leetcode.com/problems/path-with-maximum-probability/
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
Example:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
*/

class Solution {
    //Dijkstra Solution, Time Complexity of O(V^2), Space Complexity of O(V)
    //Since this question is looking for Maximum path, it is just a Dijkstra Algorithm with the use of Max Heap
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> graph(n);
        //all value in maxProb should start at 0 since the first comparison will always be 1
        vector<double> maxProb(n, 0);
        priority_queue<pair<double, int>> pq;

        //create a nested array with the stored with "connected nodes" and "accordance probability"
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }

        //because we compare with multiplication, we started the probability with 1
        pq.push({1.0, start});
        maxProb[start] = 1;
        
        while(!pq.empty()){
            //save the node and probability of current node
            int current = pq.top().second;
            double prevProb = pq.top().first;
            pq.pop();
            
            //walk through all the connected node of current node
            for(auto it : graph[current]){
                //keep going deep and update the Max Heap if the connected node has bigger probability that current node
                if(prevProb * it.second > maxProb[it.first]){
                    //update the probability of that connected node
                    maxProb[it.first] = prevProb * it.second;
                    //update max Heap for going deeper
                    pq.push(make_pair(maxProb[it.first], it.first));
                }
            }
        }
        
        return maxProb[end];
    }
};
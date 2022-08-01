/*
https://leetcode.com/problems/network-delay-time/
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
*/

class Solution {
    //Dijkstra Algorithm Solution, Time Complexity of , Space Complexity of 
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //push the connected node and weight to according node(index in adj array)
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
                adj[times[i][0]].push_back({times[i][1],times[i][2]});
        
        //create a n+1 array with INT_MAX (unvisited) since the nodes in this question started from 1 and end in n
        vector<int> dist(n+1,INT_MAX);

        //create a minHeap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //note the first node as visited
        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty())
        {
            pair<int,int> t=pq.top();
            pq.pop();
            //check the connected nodes
            for(pair<int,int> it:adj[t.second]){
                //if it is a shorter path
                if(dist[it.first] > t.first + it.second){
                    //update weight
                    dist[it.first] = t.first + it.second;
                    //push the connected node into the minHeap for keep checking
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        
        //After walked through all the possible path, check the result
        int res=0;
        //because it is possible that some nodes will never be visited, which means it could never visit all n nodes
        //therefore, we should check for any INT_MAX which indicates unvisited. Return -1 if yes
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            res=max(res,dist[i]);
        }
		return res;
	}
};

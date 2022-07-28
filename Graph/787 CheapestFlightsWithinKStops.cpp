/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/
There are n cities connected by some number of flights.
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/
class Solution {
    //Bellman-Ford Solution, Time Complexity of O(VE), Space Complexity of O(V)
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist( n, INT_MAX );
        dist[src] = 0;
        
        for( int i=0; i <= K; i++ ) {
            vector<int> tmp(dist);
            
            //Since the possible way is provided bu the question, we can just simply walk through the array
            for( auto flight : flights ) {
                //First node to check will always be dist[src] (line 12)
                if( dist[flight[0]] != INT_MAX ) {
                    //assign the weight used for that node into tmp
                    tmp[flight[1]] = min(tmp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            //why we need to use the tmp array? Because we want to check at the same moment (otherwise dist[flight[0]] will be different)
            dist = tmp;
            
        }
        //Check if the destination is possible to reach (if visited)
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

//For finding the shortest path, it suppose to use Dijkstra Algorithm for a short time complexity
//However, it is argued that it is not applied to this question because of the given parameter (TLE).
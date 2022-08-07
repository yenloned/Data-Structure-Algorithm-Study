/*
https://leetcode.com/problems/find-the-town-judge/
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
*/

class Solution {
    //In/OutDegree Solution, Time Complexity of O(V+E), Space Complexity of O(V)
    //Reference: https://www.youtube.com/watch?v=1X5WCgYXdcU&ab_channel=WrathofMath
    //InDegree: the number of edges going TO it
    //OutDegree: the number of edges going FROM it
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //Base Case if there is only judge here
        if(trust.empty() && n == 1){
            return 1;
        }
        
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);
        
        for(int i=0; i < trust.size(); i++){
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }
        
        //check if the node has no outdegree(trust no one) and n-1 indegree (trusted everyone except himself)
        for(int i=0; i <= n; i++){
            if(indegree[i] == n-1 && outdegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
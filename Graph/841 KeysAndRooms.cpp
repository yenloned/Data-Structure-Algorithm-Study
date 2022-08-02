/*
https://leetcode.com/problems/keys-and-rooms/
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
*/

class Solution {
    //DFS Solution, Time Complexity of O(m+n), Space Complexity of O(m)
    //where n is the number of keys, m is the number of rooms
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //create a array with same size to indicate which room has been visited
        vector<bool> visited(rooms.size(), false);

        //start from room 0 since it is always unlocked
        dfs(rooms, visited, 0);
        
        //check if all rooms are visited
        for(int i=0; i < visited.size(); i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
        
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int index){
        //assign that room as "visited"
        visited[index] = true;
        
        //walk through every keys in every unvisited rooms
        for(int i=0; i < rooms[index].size(); i++){
            int node = rooms[index][i];
            //if there is a key that lead to a unvisited room, start dfs there
            if(!visited[node]){
                dfs(rooms, visited, node);
            }
        }
    }
};
/*
https://leetcode.com/problems/last-stone-weight/
You are given an array of integers stones where stones[i] is the weight of the ith stone.
We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.
Return the weight of the last remaining stone. If there are no stones left, return 0.
*/

class Solution {
    //Max Heap solution, Time Complexity of O(nlogn), Space Complexity of O(n)
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        
        for(int i : stones){
            maxHeap.push(i);
        }
        
        while(maxHeap.size() > 1){  //at most 1
            int y = maxHeap.top();      //larger one
            maxHeap.pop();
            int x = maxHeap.top();      //smaller one
            maxHeap.pop();
            
            //Now, 2nodes is popped and check if new node needed to be pushed (a node is already destroyed for x == y)
            if (x != y){
                maxHeap.push(y-x);      //
            }
        }
        
        //by C++, needed a condition check here for return 0 if no nodes left
        if(maxHeap.empty()){
            return 0;
        }
        return maxHeap.top();
    }
};

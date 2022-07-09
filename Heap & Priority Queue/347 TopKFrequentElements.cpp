/*
https://leetcode.com/problems/top-k-frequent-elements/
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

class Solution {
    //Hashmap + MinHeap Solution, Time Complexity of O(nlogk), Space Complexity of O(n)
    
    //This solution is not the best solution, please see ../Sorting/347 TopKFrequentElements.cpp (Bucket Sort)
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> pmap;       //create Hashmap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;    //create minHeap
        vector<int> ans;
        
        for (int i : nums){
            pmap[i]++;                  //implement all given elements into hashmap with value and frequent
        }
        
        for (auto i : pmap){
            minHeap.push({i.second, i.first});  //push the value and frequent into minHeap
            if(minHeap.size() > k){             //Meanwhile, maintain the size of minHeap at equal or less than k
                minHeap.pop();
            }
        }
        //Now, all the elements in minHeap is the top K frequent element, because we popped h-k times in minHeap (k largest elements left)
        
        //We can now check if the element has bigger or equal frequent with the root element in minHeap
        for (auto i : pmap){
            if (i.second >= minHeap.top().first){   //If yes, it is the Top K Frequent element
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};
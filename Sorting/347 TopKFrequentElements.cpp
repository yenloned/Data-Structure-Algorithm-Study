/*
https://leetcode.com/problems/top-k-frequent-elements/
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

class Solution {
    //Bucket Sort solution, Time Complexity of O(n), Space Complexity of O(n)
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) freq[num]++;  //assigning corresponding elements and frequent into hashmap
        
        vector<vector<int>> buckets(nums.size()+1);     //create a empty array with the size of numbers of elements + 1
        for (auto [a, b] : freq)            //implement the frequent as index and the elements as value into the array
            buckets[b].push_back(a);
        
        //Originally, bucket sort will take the index as element and value as frequent
        //However, this could lead to unlimited size of array initialization in this question
        //Therefore, we could reverse the idea by index as frequent and value as elements (the size will be at most n+1)

        vector<int> res;
        for (int i = nums.size(); k > 0; i--) { //iterate the bucket array from the last index
            for (auto a : buckets[i]) {         //as long as that index exists elements and k > 0 as counter, push it into the answer array
                res.push_back(a);
                k--;
            }
        }
        
        return res;
    }
};
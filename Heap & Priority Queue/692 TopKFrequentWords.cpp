/*
https://leetcode.com/problems/top-k-frequent-words/
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
*/

class Solution {
    //Hashmap + MinHeap solution, Time Complexity of O(nlogk), Space Complexity of O(n)
    //This solution is very similar with 347 TopKFrequentElements.cpp and 451 SortCharactersByFrequency.cpp
    //However, it requires a customer compactor and different syntax with the use of pointer, since it runs with string instead of int.
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashmap;
        for(string& word : words) {
            hashmap[word] += 1;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
        for(auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> res;
        while(!pq.empty()) {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    //custom compactor, for building a minHeap with string
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
};
/*
https://leetcode.com/problems/sort-characters-by-frequency/
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
Example:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/

class Solution {
    //HashMap + MaxHeap Solution, Time Complexity of O(n), Space Complexity of O(1)
    //In this solution, some people may argue it should take O(nlogn) time and O(n) space. 
    //However, it is considered as constant since there will be only 26characters at most and we are using hashmap.
public:
    string frequencySort(string s) {
        unordered_map<char, int> pmap;
        priority_queue<pair<int, char>> maxHeap;
        
        for (char c : s){
            pmap[c]++;      //assign how many elements(value) and characters(key) into hashmap
        }
        for (auto itr : pmap){
            maxHeap.push({itr.second, itr.first});  //implementing the key and value into maxHeap by iterator
        }
        
        string ans;
        while(!maxHeap.empty()){                    //pop out the maxHeap one by one (it will be descending order)
            int freq = maxHeap.top().first;
            char c = maxHeap.top().second;
            
            //push characters to ans string by freq times
            while(freq > 0){
                ans.push_back(c);
                freq--;
            }
            
            maxHeap.pop();
            
        }
        
        return ans;
    }
};
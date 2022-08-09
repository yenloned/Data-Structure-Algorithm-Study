/*
https://leetcode.com/problems/group-anagrams/
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
    //Hashmap + Sorting(ASCII) solution, Time Complexity of O(mn), Space Complexity of O(mn)
    //where n is the size of strs, m is the maximum length of every string in strs
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //However, since we can use ASCII trick for 26English characters, the Time Complexity can be further narrow down to O(m) instead of O(mlogm)

        unordered_map <string, vector<string>> map;
        for(auto str : strs){
            //convert it as sorted string
            string key = sortStr(str);
            //since the anagram groups will have the same sorted result, assign their original string together
            map[key].push_back(str);
        }
        
        //basically just format and return back the result
        vector<vector<string>> res;
        for(auto it : map){
            res.push_back(it.second);
        }
        
        return res;
    }
    
    string sortStr(string str){
        vector<int> allChars(26, 0);
        
        //assign the number of the character into the array by ASCII subtraction
        for(auto c : str){
            allChars[c - 'a']++;
        }
        
        string key = "";
        //check every English characters
        for(int i=0; i < 26; i++){
            //push back the characters of str with sorted order
            //in C++, it is better to use to_string for best practice. However string() has a better run time in Leetcode (idk why)
            key += string(allChars[i], i + 'a');    //key.append(to_string(allChars[i] + 'a'));
        }
        
        return key;
    }
};
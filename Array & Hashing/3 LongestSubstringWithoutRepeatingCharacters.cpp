/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Given a string s, find the length of the longest substring without repeating characters.
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    //Hash Set solution, Time complexity of O(n), Space Complexity of O(n)
    //There will be another solution for this question, please see Sliding Window
    unordered_set<char> totalset;       //declare the hash set
    int res = 0, fast = 0, slow = 0;    //declare the maximum distance, fast pointer and slow pointer
    
    //while the pointer is not yet finished
    //Why don't just iterative the whole string? Because the repeated character will be skipped.
    //e.g. Input: aabc, the second character "a" will be skipped without the increment of the fast pointer which causing the pointer can not catch up the iteration
    while ( fast < s.length() ){
        //if the character is existed in the hashset, which mean repeated character
        if (totalset.find(s[fast]) != totalset.end()){
            totalset.erase(s[slow]);    //clear the character at slow pointer position(the repeated character)
            slow++;
        //not existed
        }else{
            totalset.insert(s[fast]);   //insert the first seen character
            fast++;
        }
        res = max(res, fast - slow);    //find the maximum distance between fast and slow
    };
    //If fast < slow, the result will be 1 since the first operation will always be not existed
    return res;
}

int main(){
    //custom input
    cout << "Input the string:" << endl;
    string input;
    cin >> input;

    cout << "The longest length of substring is ";
    cout << lengthOfLongestSubstring(input);
}
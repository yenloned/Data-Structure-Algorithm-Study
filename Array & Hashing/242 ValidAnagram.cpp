/*
https://leetcode.com/problems/valid-anagram/
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    //Hashmap solution, Time complexity of O(n), Space Complexity of O(n) / O(1) since maximum size will be 26
    if (s.length() != t.length()){
        return false;   //if they have different length, it must not be anagram
    }
    //create a hashmap that character as key and counter as value
    unordered_map<char, int> mapc;
    for(auto charc:s){
        //increment the counter for each character in string s. (non-existed key in C++ map will be default value of 0)
        mapc[charc]++;
    }
    for(auto chart:t){
        //decrease the counter by the character from iteration in string t
        mapc[chart]--;
        //return false if the counter(value) of that character(key) in the map is negative, which means they have a unshared character
        if (mapc[chart] < 0){
            return false;
        }
    }
    return true;
}

int main(){
    //custom input
    cout << "Input the string s:" << endl;
    string s;
    cin >> s;   //s = "anagram"

    cout << "Input the string t:" << endl;
    string t;
    cin >> t;   //t = "nagaram"
    //true
    if(isAnagram(s, t)){
        cout << "Result:\ntrue";
    }else{
        cout << "Result:\nfalse";
    }
}


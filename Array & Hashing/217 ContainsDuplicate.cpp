/*
https://leetcode.com/problems/contains-duplicate/
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> nums) {
    //Hashset solution, Time complexity of O(n), Space Complexity of O(n)
    unordered_set<int> hashset;
    //inserting the element into hashset, then check with the next element, return true once repeated element is found
    for(auto i: nums){
        if (hashset.find(i) != hashset.end()){
            return true;
        }
        hashset.insert(i);
    }
    return false;
}

int main(){
    vector<int> nums; //[1,2,3,1] -> true
    //custom input
    int size;
    cout << "Input the size of array:" << endl;
    cin >> size;

    cout << "Input the elements into array:" << endl;
    int input;
    for(int i =0; i<size;i++){
        cin >> input;
        nums.push_back(input);
    }
    
    if(containsDuplicate(nums)){
        cout << "Result:\ntrue";
    }else{
        cout << "Result:\nfalse";
    }
}
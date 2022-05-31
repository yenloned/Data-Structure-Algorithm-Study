/*
https://leetcode.com/problems/contains-duplicate/
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> numsSet;
        for(int i=0;i<nums.size();i++){
            if(numsSet.find(nums[i])!=numsSet.end()){
                return true;
            }else{
                numsSet.insert(nums[i]);
            }
        }
        return false;
    }
};
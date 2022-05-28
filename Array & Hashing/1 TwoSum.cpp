/*
https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> NumMap;
        for(int i=0;i<nums.size();i++){
            if(NumMap.find(target-nums[i])!=NumMap.end()){
                return vector<int>{i,NumMap[target-nums[i]]};
            }
            NumMap[nums[i]]=i;

        }
        return nums;
    }
};

int main(){
    Solution method;
    vector<int> testdat{2,7,11,15};
    vector<int> output = method.twoSum(testdat,9);
    cout<<"[";
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<",";
    }
    cout<<"]";
}
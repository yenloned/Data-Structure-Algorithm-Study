/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> nums, int target) {
    //hashmap solution, Time complexity of O(n), Space Complexity of O(n)
    cout << "\nThe result is:" << endl;
    map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) {
        if (hashmap.find(target - nums[i]) != hashmap.end()) {
            cout << hashmap[target - nums[i]] << " " << i;
            return {};
        }
        hashmap[nums[i]] = i;
    }
    cout << "No solution (result from custom input).";
    return {};
}

int main(){
    vector<int> nums; // = {2,7,11,15};
    int target; // = 9;

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
    
    cout << "Input the target:" << endl;
    cin >> target;

    twoSum(nums, target);
}
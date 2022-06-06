/*
https://leetcode.com/problems/3sum/
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    //Two pointers solution, Time Complexity of O(n^2), Space Complexity of O(1)
    sort(nums.begin(), nums.end()); //sort the array in order to perform two pointers
    
    if (nums.size() < 3){   //Base Case1; the array should be at least contain 3elements
        return {};
    }
    if (nums[0] > 0){       //Base Case2; the first element(minimum element) should be <= 0 after sorted
        return {};
    }
    
    vector<vector<int>> res;    //create the nested array for return
    for(int i=0;i<nums.size();++i){ //iterative the input
        if (nums[i] > 0){   //Similar concept with Base Case2, stop the WHOLE iteration if the current element is greater than 0.
            break;
        }
        if (i > 0 && nums[i] == nums[i-1]){     //skip the current iteration if the current element is same as last element (already checked)
            continue;
        }
        
        //declare the left pointer, right pointer, and the sum value
        int l = i + 1;
        int r = nums.size() - 1;
        int sum = 0;
        
        while (l < r){      //search between two pointers
            sum = nums[l] + nums[r] + nums[i];
            //Similar concept with binary search, check the sum with the value in pointers and current element positions.
            if (sum>0){         //the sum is too big, move right pointer -1
                r--;
            }else if (sum<0){   //the sum is too small, move left pointer +1
                l++;
            }else{              //the sum is 0, which mean we found the combination
                res.push_back({nums[i], nums[l], nums[r]});     //add the combination into the return array
                //check the edge case to avoid repeated elements for both left and right pointers, update them until there is no repeated elements
                int last_l = nums[l] , last_r = nums[r];
                while(nums[l] == last_l and r > l){
                    l++;
                }
                while(nums[r] == last_r and r > l){
                    r--;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums; // = {-1,0,1,2,-1,-4} -> {[-1,-1,2],[-1,0,1]};

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
    
    cout << "Result:" << endl;
    vector<vector<int>> res = threeSum(nums);
    for (const auto & i : res){
        for (auto j : i){
            cout << j << " ";
        }
    }
}


/*
https://leetcode.com/problems/binary-search/
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
 If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>

using namespace std;

int binarysearch(vector<int>& nums, int target) {
    //declare the mid pointer, left pointer, and right pointer
    int m = nums.size() / 2;
    int l = 0; 
    int r = nums.size() - 1;
    
    while(l <= r){
        if (nums[m] > target){          //the mid pointer is too big (which means the target on left side)
            r = m - 1;              //update the right pointer to the left of mid pointer (minimize the range to left side)
        }else if (nums[m] < target){    //the mid pointer is too small (which means the target on right side)
            l = m + 1;              //update the left pointer to the right of mid pointer (minimize the range to right side)
        }else{                          //found the target
            return m;
        }
        m = (l+r) / 2;              //update the mid pointer after every range minimize
    }
    return -1;      //if the function is not finished within the while loop, it means the result is not found
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

    int res = binarysearch(nums, target);
    cout << "Result: " << res;
}
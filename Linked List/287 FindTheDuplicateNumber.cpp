/*
https://leetcode.com/problems/find-the-duplicate-number/
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
*/

class Solution {
    //Floyd Cycle solution, Time Complexity of O(n), Space Complexity of O(1)
public:
    int findDuplicate(vector<int>& nums) {
        //In this question, there *MUST be a duplicate number* and we *CAN NOT modify the given list* and *contain any extra space*.
        //In other words, solution like sorting and hashmap will not be accepted.
        //Therefore, Floyd Cycle Detection Algorithm (a.k.a Tortoise and Hare Algorithm) should be used.

        //Create slow and fast pointers for Tortoise and Hare
        int slow = 0;
        int fast = 0;
        
        //In this question, numbers in the range of 1 to n inclusive. Therefore, their value can be the position for next pointers *IMPORTANT*.
        //Meanwhile, a endless cycle will be formed, and Tortoise and Hare Algorithm can be applied
        do{
            slow = nums[slow];          //move one step for slow pointer (nums[pointer])
            fast = nums[nums[fast]];    //move two steps for fast pointer (nums[pointer] -> nums[pointer])
        }while(slow != fast);       //until they meet each other
        
        //Now, two pointers are on the same position.
        //Mathematically, the distance between start and duplicate number, is same as meeting pointer and duplicate number
        /*
        y = distance between start and duplicate
        x = distance between meeting and duplicate
        c = the circle
        c - x = the circle end at meeting
        2slow = fast
        2(y+c-x) = y+2c-x
        y = x
        */
        //Therefore, find the meet point from start and meeting point by applying both slow pointers
        int res = 0;
        do{
            res = nums[res];        //move one step (nums[pointer])
            slow = nums[slow];      //move one step (nums[pointer])
        }while(res != slow);
        
        //return that meet point
        return res;
    }
};
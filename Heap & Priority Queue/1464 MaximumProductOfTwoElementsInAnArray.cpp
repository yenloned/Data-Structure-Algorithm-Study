/*
https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
Example:
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
*/

class Solution {
    //Priority Queue Solution, Time Complexity of O(n), Space Complexity of O(n)
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        
        for(int i=0; i< nums.size(); i++){
            pq.push(nums[i]);
        }
        
        int i = pq.top()-1;
        pq.pop();
        int j = pq.top()-1;
        
        return i*j;
    }
    //This solution is not the best solution since it takes extra O(n) memory, but it is a good demonstration of the usage of Priority Queue
};

/*Time Complexity of O(n), Space Complexity O(1) Solution:
    int maxProduct(vector<int>& nums) {
        int m1=nums[0],m2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=m1){
                m2=m1;
                m1=nums[i];
            }else{
                if(nums[i]>m2){
                    m2=nums[i];
                }
            }
        }
        return (m1-1)*(m2-1);
    }
*/
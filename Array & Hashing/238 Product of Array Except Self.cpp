//Question: https://leetcode.com/problems/product-of-array-except-self/
//Time Complexity: O(n)+O(n) = O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int sum=1;
        //O(n)
        //calculate the product of previous numbers 
        for(int i=0;i<nums.size();i++){
            ans.push_back(sum);
            sum *=nums[i];
        }
        //O(n)
        //calculate the product of numbers after
        sum=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=sum;
            sum *=nums[i];
        }
        return ans;
    }
};
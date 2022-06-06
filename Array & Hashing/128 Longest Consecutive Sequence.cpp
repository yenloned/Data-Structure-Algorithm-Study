//Question: https://leetcode.com/problems/longest-consecutive-sequence/
//Time Complexity: O(nlog(n))
//Space Complexity: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        //sort() Time Complexity: O(nlog(n))
        sort(nums.begin(),nums.end());
        int ans=1,temp =1;
        //Time:O(n)
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1){
                temp++;
            }else if(nums[i+1]==nums[i]){
                continue;
            }else{
                if(temp>ans){ans=temp;}
                temp=1;
            }
        }
        if(temp>ans){ans=temp;}
        return ans;
    }
};

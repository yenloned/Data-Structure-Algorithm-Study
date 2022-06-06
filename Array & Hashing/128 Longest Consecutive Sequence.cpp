//Question: https://leetcode.com/problems/longest-consecutive-sequence/
//Time Complexity O(nlog(n)+n-1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        //sort() Time Complexity: O(N log(N))
        sort(nums.begin(),nums.end());
        int ans=1,temp =1;
        //O(n-1)
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
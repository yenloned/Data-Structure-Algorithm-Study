class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0){if(nums[i]==nums[i-1]){continue;};}
            int j=i+1;
            int k = nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }else{
                    ans1.insert({nums[i],nums[j],nums[k]});
                    k--;
                    j++;
                }
            }
        }
        return vector<vector<int>>(ans1.begin(),ans1.end());
    }
};
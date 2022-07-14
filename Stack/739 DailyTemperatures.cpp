/*
https://leetcode.com/problems/daily-temperatures/
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

class Solution {
    //Stack Solution, Time Complexity of O(n), Space Complexity of O(n)
    //Personally I think this question is kinda complicated, please refer to https://www.youtube.com/watch?v=cTBiBSnjO3c&ab_channel=NeetCode
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //stack<day, temperature>
        stack<pair<int,int>> stk;
        vector<int> ans(temperatures.size());
        
        for (int i = 0; i < temperatures.size(); i++){  //walk the given array
            int curDay = i;
            int curTemp = temperatures[i];
            
            //if the warmer temperature is found
            while(!stk.empty() && curTemp > stk.top().second){
                int prevDay = stk.top().first;
                
                //push the distance between that [found temperature] and [current temperature] into [the index] of that found temperature
                ans[prevDay] = curDay - prevDay;
                //since we checked the top element, we could pop it off
                //meanwhile, the stack might have a new top element which will be checked by while loop above
                //In other words, this action could help us to check the previous skipped element (For example, continuos colder elements )
                stk.pop();
            }
            //push every element into stack with day and temperature
            stk.push({curDay, curTemp});
        }
        
        return ans;
        
    }
};
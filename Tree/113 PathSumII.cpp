/*
https://leetcode.com/problems/path-sum-ii/
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
Example:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //DFS Solution, Time Complexity of O(n), Space Complexity of O(n)
public:
    //Global variable
    vector<int> path;
    vector<vector<int>> ans;
    
    void dfs(TreeNode* cur, int sum,int target){
        if(!cur) return;        //Base Case for recursion
        
        sum += cur->val;            //adding current node value into sum
        path.push_back(cur->val);   //adding current node into path
        
        //Check if it is the path we looking for when DFS reaches the edge
        if(!cur->left && !cur->right){
            if(sum == target)            
                ans.push_back(path);    //adding the path we made into ans
        }
        //Continue DFS if not reached the edge
        else{
            dfs(cur->left,sum,target);  
            dfs(cur->right,sum,target);
        }
        
        //clear the path for the next path checking
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        dfs(root,0,targetSum);
        return ans;
    }
};
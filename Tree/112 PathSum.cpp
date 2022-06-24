/*
https://leetcode.com/problems/path-sum/
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;       //Base Case
        }

        targetSum = targetSum - root->val;  //decrease the sum value in each recursion

        if(sum==0 && !root->left && !root->right){ 
            return true;        //true if the current node value equal to sum(after all the decrement) and reach the edge
        }

        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);   //recursion and passing the decreased sum
    }
};
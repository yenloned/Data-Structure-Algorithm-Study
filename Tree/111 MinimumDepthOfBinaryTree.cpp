/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.
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
    //Recursion solution, Time Complexity of O(n), Space Complexity of O(n)
public:
    int minDepth(TreeNode* root) {
        if (!root){
            return 0;   //Base Case of recursion
        }

        //In this question, it WILL NOT return 1 if there is no next node on the either side
        //Instead, it will return the another side
        //Therefore, we should find the maximum depth of both side first

        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);
        
        //Check if one of the side has no nodes (0 height)
        if (leftHeight == 0 || rightHeight == 0){
            return 1 + max(leftHeight, rightHeight);    //then just return the side with heights
        }
        
        return 1 + min(leftHeight, rightHeight);        //return the minimum height for each leaf (original solution if 1 will be returned)
    }
};
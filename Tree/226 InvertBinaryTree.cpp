/*
https://leetcode.com/problems/invert-binary-tree/
Given the root of a binary tree, invert the tree, and return its root.
Example:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
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
    //DFS Solution, Time Complexity of O(n), Space Complexity of O(h) where n is the number of nodes and h is the height of the tree.
public:
    TreeNode* invertTree(TreeNode* root) {
        //Base Case for recursion
        if (!root){
            return NULL;
        }
        
        //temp node for swapping
        TreeNode *temp;
        //swap the left and right node in the following subtree
        temp = root->right;
        root->right = root->left;
        root->left = temp;
        
        //recursion from left to right (DFS)
        invertTree(root->left);
        invertTree(root->right);

        //since it is recursion (call stack) by depth heights + temp node in every call, it takes O(h) extra memory.
        return root;
    }
};
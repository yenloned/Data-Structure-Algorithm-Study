/*
https://leetcode.com/problems/symmetric-tree/
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
        return recursion(root->left, root->right);      //Start recursion
    }
    
    bool recursion(TreeNode* left, TreeNode* right){
        if (!left && !right){   //Base case, reached the edge
            return true;
        }
        
        //return false if one of them is empty and one of them is not, or they have different value (they are not mirrored)
        if (!left || !right || left->val != right->val){
            return false;
        }
        
        //Noted that we are finding a mirror of the subtree. Therefore the opposite node should be inputted for recursion
        //right, left && left, right
        return recursion(left->right, right->left) && recursion(left->left, right->right);
    }
};
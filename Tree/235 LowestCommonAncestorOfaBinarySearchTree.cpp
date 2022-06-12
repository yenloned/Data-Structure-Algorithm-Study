/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
*(where we allow a node to be a descendant of itself)*.

Ancestor = parent / parent's parent's parent ...
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    //Time Complexity is the height of a binary tree (O(logn)), where n is the numbers of node, Space Complexity of O(1)
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //Based on Binary Tree structure
        while(root){
            //if they both greater than current root, it means the answer will be on the right side
            if (p->val > root->val && q->val > root->val){
                root = root->right;
            //if they both smaller than current root, it means the answer will be on the left side
            }else if (p->val < root->val && q->val < root->val){
                root = root->left;
            //if they smaller+bigger / equal to the current node, it means the answer will be the current note
            }else{
                return root;
            }
        }
        //the return for C++ syntax (can be ignored because it is assumed there will be answer)
        return root;
    }
};
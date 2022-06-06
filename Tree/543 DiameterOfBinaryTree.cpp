/*
https://leetcode.com/problems/diameter-of-binary-tree/
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
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
    //DFS Recursion, Time Complexity of O(n), Space Complexity of O(h)
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        dfs(root, d);
        return d;
    }
    
    int dfs(TreeNode* root, int &d) {
        if(!root){
            return 0;
        }
        int ld = dfs(root->left, d);        //left subtree
        int rd = dfs(root->right, d);       //right subtree
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
};
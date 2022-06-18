/*
https://leetcode.com/problems/validate-binary-search-tree/
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    //DFS Inorder Solution, Time Complexity of O(n), Space Complexity of O(n)
    //For this question, it is argued that O(1) Space Complexity could be achieved.
    //However, DFS Recursion solution is more concise and easier to understand
    //It is recommended to do this problem again
public:
    //In this solution, the check of range will be used as the main concept
    //Because we need to check if not only the left < parent && right > parent, but also all nodes in left subtree < root && all nodes in right subtree > root
    bool dfs(TreeNode* node, TreeNode* left, TreeNode* right){
        //Base Case, tree without nodes is BST / it reached the edge
        if (!node){
            return true;
        }
        //Check left < parent < right. If not, it broke the rule of BST
        if ( (left && node->val <= left->val) || (right && node->val >= right->val)) {
            return false;
        }
        /*
        How to check if left subtree < root && all nodes in right subtree > root? (not only parent node but subtree)
        This is where the tricky part (personally think it is)
        For going left:
            The left boundary remains same and update the right boundary
        For going right:
            The right boundary remains same and update the left boundary
        e.g. root->left->right
            Then both left and right boundary will be updated and checked
        */
        return dfs(node->left, left, node) && dfs(node->right, node, right);
    }
    
    bool isValidBST(TreeNode* root) {
        //Because INT_MAX and INT_MIN are buggy for leetcode test cases, it is better to start with NULL node
        return dfs(root, NULL, NULL);
    }
};
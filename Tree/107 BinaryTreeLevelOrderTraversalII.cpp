/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
(i.e., from left to right, level by level from leaf to root).
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

//In this question, it is very similar with 102 Binary Tree Level Order Traversal.
//The only difference is a bottom-up level order traversal instead of BFS level order
//Therefore, one of the solution is exactly the same as 102 BinaryTreeLevelOrderTraversal.cpp and reverse the answer vector at the end.
//Time Complexity of O(n). Space Complexity of O(n)

//However, it is recommended to use an alternative solution


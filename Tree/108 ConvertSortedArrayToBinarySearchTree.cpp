/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
Given an integer array nums where the elements are sorted in ascending order, convert it to a *height-balanced* binary search tree.
A *height-balanced* binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
Example:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted
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
    //Recursion + Binary Search like Solution, Time Complexity of O(n), Space Complexity of O(logn) 
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
    
    //Ascending order array is basically the result of DFS inorder traversal
    //Since the question asked for a balanced height tree, we can know that the middle of will be the root node
    TreeNode* buildTree(vector<int>& nums, int l, int r){
        if(l > r){
            return NULL;        //Base Case
        }
        //Finding the mid point
        int m = (l+r)/2;
        //Create the node by the mid point (every node is the root node of their own subtree)
        TreeNode* root = new TreeNode(nums[m]);
        //Recursion for all nodes
        root->left = buildTree(nums, l, m-1);       //Because of BST, we know that it must be smaller on the left
        root->right = buildTree(nums, m+1, r);      //and it must be bigger on the right
        
        return root;
    }
};
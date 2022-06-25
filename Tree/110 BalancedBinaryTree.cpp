/*
https://leetcode.com/problems/balanced-binary-tree/
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
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
    //Bottom Up Solution, Time Complexity of O(n), Space Complexity of O(n)
public:
    bool answer = true;     //global boolean

    int height(TreeNode* node){
        if(!node){
            return 0;
        }
        int leftHeight = height(node->left);        //start from left subtree
        int rightHeight = height(node->right);      //start from right subtree
        
        if (abs(leftHeight - rightHeight) > 1){     //make the global boolean false If they have difference bigger than 1
            return answer = false;
        }
        return max(leftHeight, rightHeight) + 1;    //finding the maximum depth for both left and right subtree by recursion, see 104 MaximumDepthofBinaryTree.cpp
    }
    
    bool isBalanced(TreeNode* root) {
        height(root);
        return answer;  //return the global boolean
    }
};
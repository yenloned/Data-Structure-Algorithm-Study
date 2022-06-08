/*
https://leetcode.com/problems/same-tree/
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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
    //DFS Recursion Solution, Time Complexity of O(min n), Space Complexity of O(min h)
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Base Case1: both the current nodes do not existed
      if(!p && !q){
          return true;
      }
        //Base Case2: one of the current nodes do not existed
      if(!p || !q){
          return false;
      }
        //Base Case3: the current nodes have the same value
      if(q->val != p->val){
          return false;
      }
      //If it is the same tree, p and q will be both not existed after the leaf nodes

      //If all the nodes passed Base Case2 and 3, it will return true in the end
      return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};
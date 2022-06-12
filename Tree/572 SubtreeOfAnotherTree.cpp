/*
https://leetcode.com/problems/subtree-of-another-tree/
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
Example:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
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

//This question is similar with 100 SameTree.cpp, it is kinda confusing and I personally dont like it. (recommended for revision)
class Solution {
public:
   bool isSubtree(TreeNode* s, TreeNode* t) {
         if(!s){
             return false;
         }
         else if(isSametree(s,t)){
             return true;
         }
         else{
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
   }
   bool isSametree(TreeNode* s, TreeNode* t){
       if(!s || !t){
           return s==NULL && t==NULL;
       } 
       else if(s->val == t->val){    
           return isSametree(s->left,t->left) && isSametree(s->right,t->right);
       }
       else{
           return false;
       }
   }
};
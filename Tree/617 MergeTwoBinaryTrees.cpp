/*
https://leetcode.com/problems/merge-two-binary-trees/
You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
Otherwise, the NOT null node will be used as the node of the new tree.
Return the merged tree.
Note: The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2){  //Base Case: recursion ended when both trees ended
            return NULL;
        }else if(!root1){       //Base Case: recursion for root1 ended, then only root2 needed to form the next new node
            return root2;
        }else if(!root2){       //Base Case: recursion for root2 ended, then only root1 needed to form the next new node
            return root1;
        }
        
        //Create the new tree by the sum of values of 2 roots
        //In this step, we could edit root1/root2 to avoid the extra memory. However, editing the input/question usually is not a good practice
        TreeNode* node = new TreeNode(root1->val + root2->val);
        //Start recursion by the left and right of new tree
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        
        return node;
    }
};
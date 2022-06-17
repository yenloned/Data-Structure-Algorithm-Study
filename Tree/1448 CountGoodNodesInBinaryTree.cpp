/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.
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
    //DFS Inorder Solution, Time Complexity of O(n), Space Complexity of O(h) / O(logn) as binary tree
public:
    int dfs(TreeNode* root, int maxVal){
        //Base Case for recursion
        if(!root) return 0;

        int count = 0;
        //check if the current node is the greatest, it is a good node if yes
        if(root->val >= maxVal){
            maxVal = root->val;     //update maximum value for checking the next node
            count = 1;              //update count as good node
        }
        
        //return 1 or 0 (good node or not) and start recursion
        return count + dfs(root->left, maxVal) + dfs(root->right, maxVal);
        //In the end, it will return the total numbers of good node
    }

    int goodNodes(TreeNode* root){
        //Base Case
        if(!root) return 0;
        
        //passing root node as starting the recursion
        return dfs(root, root->val);
    }
    
    
};
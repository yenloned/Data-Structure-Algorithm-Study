/*
https://leetcode.com/problems/delete-node-in-a-bst/submissions/
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
Example:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
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
    //Recursive Solution, Time Complexity of O(h)/O(logn) / Worst Case O(n), Space Complexity of O(n)
    //For full explanation: https://www.youtube.com/watch?v=gcULXE7ViZw&ab_channel=mycodeschool
public:
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;     //Base Case for recursion
        
        //finding the key node as BST
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        
        //Found it
        else {
            //Case 1: It has no children (left node), then just delete it (free memory)
            if (!root->left && !root->right){
                delete root;
                return NULL;
            }
            //Case 2: It has only one children, then we will replace the 
            else if (root->left == NULL) {      //only has left child
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            else if (root->right == NULL) {     //only has right child
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            //Case 3: It has two children, we can either find the maximum node in left subtree or the minimum node in right subtree, then replace it
            else {
                TreeNode* tmp = findMin(root->right);               //find the minimum node in right subtree
                root->val = tmp->val;                               //then assign the key node to minimum node we found
                root->right = deleteNode(root->right, tmp->val);    //delete the original minimum node (free memory)
            }
        }
        
        return root;
    }
};
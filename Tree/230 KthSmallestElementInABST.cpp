/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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

//This question is solved by DFS Inorder solution, we can find the sorted order of all nodes since BST is a ordered tree
//Iteration and Recursion way will be shown below

//Recursive
class Solution {
    //Time Complexity of O(h)/O(logn) as BST in average, O(n) in worst
    //Space Complexity of O(h)/O(logn) as BST in average, O(n) in worst
    //Inorder: left -> parent -> right
public:
    int res;                    //Global variable for the answer
    void inorder(TreeNode* root, int& k) {
        if (!root) return;      //Base Case for recursion

        //Go left side first
        inorder(root->left, k);
        //Check parent, it is the answer if k met 0
        k--;
        if (k == 0){
            res = root->val;
        }
        //Go right side last
        inorder(root->right, k);

        /*
        How we know it is the answer if k met 0?
        1. By the recursion, the traversal will go to the leftest node (smallest node) first
        2. Then, by the call stack, it will check the parent node (the top function in the stack)
        At that moment, the k will start decreasing to find the kth smallest node in every function (started from the most left)
        3. Finally, it will check the right node
        In order words, we will start counting from the smallest node (by recursion) and check the nodes by ascending order (by call stack)
        */
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }

};

//Iterative, similar concept with Recursion but use stack instead
class Solution {
    //Time Complexity of O(h)/O(logn) as BST in average, O(n) in worst
    //Space Complexity of O(h)/O(logn) as BST in average, O(n) in worst
    //Inorder: left -> parent -> right
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            
            k--;
            if (k == 0){
                return root->val;
            }

            root = root->right;
        }
        return -1;  //return for C++ syntax (can ignore)
    }
};

/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/
You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children.

Example:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
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
    int ans = 0;        //Global variable
    int sumNumbers(TreeNode* root) {
        recursion(root, ans);   //Start recursion (start by 0)
        return ans;
    }
    
    void recursion(TreeNode* node, int sum){
        if (!node){         //Base Case for recursion
            return;
        }
        
        if(!node->left && !node->right){    //Base Case for reaching the leaf node
            sum = sum*10 + node->val;
            ans += sum;     //Putting the sum value into global variable
            return;
        }
        
        //DFS, increasing one position(*10) in each recursion (next level)
        recursion(node->left, sum*10 + node->val);
        recursion(node->right, sum*10 + node->val);
    }
};

 
/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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

//There is 3 solutions for this question

//DFS Recursion, Time Complexity of O(n), Space Complexity of O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//DFS Iterative, Time Complexity of O(n), Space Complexity of O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        if (!root) return max_depth;
        
        //Use of stack
        stack<pair<int, TreeNode*>> s; s.emplace(1, root);
        while (!s.empty()){

            const auto& p = s.top();
            s.pop();
            int depth = p.first;
            TreeNode* t = p.second;

            max_depth = max(max_depth, depth);
            
            if (t->left != nullptr) s.emplace(depth + 1, t->left);
            if (t->right!= nullptr) s.emplace(depth + 1, t->right);
        }
        
        return max_depth;
    }
};

//BFS Iterative, Time Complexity of O(n), Space Complexity of O(n)
class Solution {
public:
    int maxDepth(TreeNode *root){
        if(!root){
            return 0;
        }

        int level = 0;
        //Use of queue
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            for(int i = 0, n = q.size(); i < n; ++ i){
                TreeNode *p = q.front();
                q.pop();

                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
            level++;
        }
        return level;
    }
};
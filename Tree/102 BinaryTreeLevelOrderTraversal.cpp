/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
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
    //BFS solution, Time Complexity of O(n). Space Complexity of O(n)
    //This question is basically a BFS question, which required to return a nested list, that's it!
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        //Base Case
        if(!root) return answer;

        queue<TreeNode*> q;  //queue is used in BFS
        q.push(root);  //push root initially to the queue

        while(!q.empty()){          //until all nodes are pushed into the queue
            int size=q.size();      //storing queue size for while loop
            vector<int> v;          //for storing nodes at the same level
            while(size--){
                TreeNode* temp=q.front();   //store the front node (node value)
                q.pop();                    //then pop it out
                v.push_back(temp->val);     //push it as the same level

                if(temp->left) q.push(temp->left);  //because of BFS, store left first (if exist)
                if(temp->right) q.push(temp->right);  //store right after (if exist)
                //this pushing order will form a BFS traversal (level first, then left to right)
            }
            answer.push_back(v);  //push the vector of the same level into answer
        }
        return answer;
    }
};
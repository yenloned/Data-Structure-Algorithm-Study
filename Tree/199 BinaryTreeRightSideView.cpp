/*
https://leetcode.com/problems/binary-tree-right-side-view/
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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
    //BFS Solution, Time Complexity of O(n), Space Complexity of O(n)
    //This solution is similar with 102 BinaryTreeLevelOrderTraversal as BFS
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        //Base Case
        if (!root) return answer;
        
        queue<TreeNode*> q;         //using queue for BFS
        q.push(root);
        
        while (!q.empty()){         //Travel all nodes
            TreeNode* right;        //the most right node at that level is what we looking for
            int size = q.size();
            
            for(int i=0;i<size;i++){        //for loop as the size of that level (in order to find the most right node)
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp) right = temp;      //The last valid node will be the most right node
                if(temp->left) q.push(temp->left);      //Because of BFS, , store left first (if exist)
                if(temp->right) q.push(temp->right);    //store right after (if exist) for next level (next while loop)
            }
            
            if (right){             //Add condition before inserting since there will be null node
                answer.push_back(right->val);              
            }
        }
        
        return answer;
    }
};
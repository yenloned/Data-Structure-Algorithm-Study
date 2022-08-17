/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    //BFS Right to Left Solution, Time Complexity of O(N), Space Complexity of O(W)
    //where N is the number of nodes, W is the width of tree
public:
    Node* connect(Node* root) {
        
        if(!root) return nullptr;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()){
            //fixed the level size at this moment
            int size = q.size();
            //set the temp node as NULL for every new level
            Node* rightNode = nullptr;
            //iterate the same level
            while(size--){
                //start from the most right node
                Node* cur = q.front();
                q.pop();
                //the first node (most right) will point to NULL (temp node in first new level)
                cur->next = rightNode;
                //assign the temp as the current node for next iteration (the left nodes will point to the right)
                rightNode = cur;
                
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
        
        return root;
    }
};
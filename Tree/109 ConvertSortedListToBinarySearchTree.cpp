/*
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    //Recursion + Floyd Cycle Solution, Time Complexity of O(nlogn), Space Complexity of O(logn)
public:
    TreeNode* sortedListToBST(ListNode* head){
        return sortedListToBST(head, NULL);     //function overloading
    }

    //In this question, the order of a BST should be the mid point of every portion (like binary search)
    /*For Example
        Linked List: [1->2->3->4->5->6->7->8->9->10]
        BST: [5->3->8....]
    */
    
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail){
        if (!head || head == tail){             //Base Case for recursion
            return NULL;
        }
        
        ListNode* fast = head, *slow = head;    //finding the mid point by fast and slow pointers
        while (fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //create a new node as current node by the value of mid node(Linked List)
        TreeNode* mid = new TreeNode(slow->val);
        mid->left = sortedListToBST(head, slow);        //recursion for left side (smaller)
        mid->right = sortedListToBST(slow->next, tail); //recursion for right side (bigger)
        
        return mid;
    }
};
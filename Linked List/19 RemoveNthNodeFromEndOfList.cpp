/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    //Two pointer solution, Time Complexity of O(n), Space Complexity of O(1)
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Base Case, if there is only one node
        if (!head->next){
            return NULL;
        }
        
        //declare the temp nodes
        ListNode *dummy = new ListNode(0, head);    //the node before the head node
        ListNode *left = dummy;                     //the left node, act as the previous node of target (Nth node)
        ListNode *right = head;                     //the right node, act as the tail position
        
        while (n > 0 && right){     //move right node by n times, because tail and target node will have the distance of n 
            right = right->next;
            n--;
        }
        while(right){               //move both pointers until the right node reach the tail
            right = right->next;
            left = left->next;
        }

        //They maintain the distance of n and the right node has reached the tail.
        //So now the left node is the previous node of the target.
        left->next = left->next->next;  //Therefore, assign the next node of left node as the next node of the target
        //The target node has been removed since no node pointing at it.
        return head;
    }
};
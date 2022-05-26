/*
https://leetcode.com/problems/reorder-list/
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
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
    //Two pointers (Reverse Linked List + Merge Linked List) solution; Time Complexity of O(n), Space Complexity of O(1)
public:
    void reorderList(ListNode* head) {
        //Base Case
        if (!head) return;
        
        //declare fast and slow pointers according to Tortoise and Hare Algorithm
        ListNode *tmp = head;
        ListNode *half = head;
        //When the fast pointer reach to the end, the slow pointer(half) will be the middle of the linked list
        while (tmp->next && tmp->next->next){
            tmp = tmp->next->next;
            half = half->next;
        }
        
        //With the middle of Linked List, reverse the second half part
        ListNode *prev = NULL;
        //Reverse a linked list from middle(half)
        while (half) {
            tmp = half->next;   //temp node for next
            half->next = prev;  //reverse current node by temp node in the back
            prev = half;        //temp node in the back move forward
            half = tmp;         //current node move forward
        }
        
        //After the second half part is reversed, merge two linked list with required order
        ListNode *first = head;     //the head node of the first part
        ListNode *second = prev;    //the head node of the second part
        while (first && second) {
            //declare the temp node for both part
            tmp = first->next;
            prev = second->next;
            //assign the next node for both part
            first->next = second;   //L1 -> Ln
            second->next = tmp;     //Ln -> L2
            //Now, the pattern of L1-> Ln -> L2 -> Ln-1... is formed
            //Move the head node one step forward for both part, prepare for the next iteration
            first = tmp;
            second = prev;
        }

        //Now, the linked list is reordered
        //We can return the head node since we have not modified it. Instead, we use temp node like "tmp", "half", and "first" as a reference/dummy.
        //However, it is a void function in question. In real case, the linked list is reordered and "head" is pointing at the head node.
    }
};
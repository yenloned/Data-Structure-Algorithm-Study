/*
https://leetcode.com/problems/reverse-linked-list/
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

//reverse a Linked List solution
ListNode* reverseList(ListNode* head) {
    //Iterative solution, Time Complexity of O(n), Space Complexity of O(1)
    //declare 2 temp nodes (next and previous)
    ListNode *nextNode, *prevNode = NULL;
    //Iterative the whole linked list
    while (head) {
        nextNode = head->next;      //Assign a temp node to the current node's next node.
        //Now, a temp node is created and nothing changed.
        head->next = prevNode;      //Assign current node's next node to previous node.
        //Now, the next node of current node will assign to the previous node (reversed order).
        //Since the reverse is done, now we should prepare for the next loop
        prevNode = head;            //Assign previous temp node to current node
        head = nextNode;            //Assign current node to the next temp node.
        //Now, every nodes have moved one step forward for the next loop.
    }
    return prevNode;
}

ListNode* reverseList(ListNode* head) {
    //Iterative solution, Time Complexity of O(n), Space Complexity of O(n) / O(1)
    if (!head || !(head -> next)) {
        return head;
    }
    ListNode* node = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return node;
}




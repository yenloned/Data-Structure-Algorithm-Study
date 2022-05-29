/*
https://leetcode.com/problems/linked-list-cycle-ii/
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter.

Do not modify the linked list.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    //Floyd Cycle Detection Algorithm Solution, Time Complexity of O(n), Space Complexity of O(1)
public:
    ListNode *detectCycle(ListNode *head) {
        //Base Case, there must not be a cycle if less than 2 nodes existed
        if (!head|| !head->next)
            return NULL;

        ListNode *slow  = head;         //slow pointer
        ListNode *fast  = head;         //fast pointer
        ListNode *entry = head;         //the return node

        while (fast->next && fast->next->next) {    //Iterate until the slow and fast pointer met
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {                     //Now, the slow pointer is with fast pointer
                while(slow != entry) {              //move the return node (started from head) and the slow pointer (same position with fast) until they met
                    slow  = slow->next;
                    entry = entry->next;
                }
                return entry;                       //In the position of they met, it is the begin of cycle
            }
            //This is the double usage of Floyd Cycle Detection Algorithm
        }
        return NULL;    //If the while loop above ended, which mean there is no cycle
    }
};
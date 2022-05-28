/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
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
    //Two Pointers solution, Time Complexity of O(n), Space Complexity of O(1)
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //Base Case, if the numbers of node in the Linked List is less than 2, that means it will have no duplicate
        if (!head || !head->next){
            return head;
        }
        //Create the temp nodes
        ListNode * dummy = new ListNode(0, head);   //Dummy node for the answer return, since the head node will be modified
        ListNode * prev = dummy;                    //Previous node to remove the duplicates (left pointer)
                                                    //Head node will be the used for iteration (right pointer)
        //Iterate the whole Linked List
        while (head){
            if(head->next && head->val == head->next->val){         //Once duplicate is detected,
                while(head->next && head->val == head->next->val){  //move the right pointer to the last duplicate since we need to remove all nodes of it
                    head = head->next;
                }
                prev->next = head->next;    //Remove them by assigning the next node of left pointer
            }else{
                prev = prev->next;          //Only move the left pointer when there is no duplicate
                //When there is duplicates, the left and right pointer will still be next to each other after the removal.
                //At that moment, we should not move the left pointer otherwise they will be stacked at the same position.
            }
            head = head->next;      //Move right pointer for iteration
        }
        
        return dummy->next;         //Return the dummy since head already moved to the end
    }
};
/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
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
        if(!head || !head->next){
            return head;
        }
        //declare two pointers
        ListNode * prev = head;         //The node point at n
        ListNode * cur = head->next;    //The node point at n+1
        
        //Since the Linked List is sorted, the two pointers that next to each other can check if there is any duplicates
        while(cur){                     //Iterate the whole linked list
            //check duplicates
            if(prev->val == cur->val){
                prev->next = cur->next;         //remove the duplicate node by assign the next node at prev to the next node at cur
                //The duplicate will be removed since there has no nodes pointing at it
            }else{
                prev = prev->next;              //Only move the prev node if the duplicate is not found
                //It is because there may contains more than 1 duplicate continuously. (e.g. 1->1->1->2)
            }
            cur = cur->next;                    //Move the cur node in every iteration
        }
        
        return head;
    }
};
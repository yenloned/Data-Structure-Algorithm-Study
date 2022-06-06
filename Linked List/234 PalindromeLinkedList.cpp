/*
https://leetcode.com/problems/palindrome-linked-list/
Given the head of a singly linked list, return true if it is a palindrome.
Example:
Input: head = [1,2,2,1]
Output: true
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
    //Two Pointers + Reverse Linked List Solution, Time Complexity of O(n), Space Complexity of O(1)
    //Tortoise and Hare Algorithm will be used
public:
    bool isPalindrome(ListNode* head) {
        //declare slow and fast pointer
        ListNode *slow = head;
        ListNode *fast = head;
        
        //When fast pointer reached the end, the slow pointer will be the middle of the Linked List
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Now, we can reverse the second half part by using slow pointer and others temp nodes
        ListNode *prev = NULL;
        ListNode *temp = new ListNode();
        while(slow){
            temp = slow->next;          //temp node for next position
            slow->next = prev;          //reverse current node
            prev = slow;                //move previous temp node forward for next reverse
            slow = temp;                //move temp node forward for next reverse
        }
        
        //Now, we can check the Palindrome with first half and second half (reversed)
        while(prev){
            if(head->val != prev->val){
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        
        return true;
    }
};
/*
https://leetcode.com/problems/swap-nodes-in-pairs/
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
Example:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
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
    //Two Pointers Solution, Time Complexity of O(n), Space Complexity of O(1)
    //This question involves a lot of edge case and complicated assignment. It is suggested to draw the step while thinking about the process.
public:
    ListNode* swapPairs(ListNode* head) {
        //Base Case, no swap needed if there is less than two nodes existed
        if(!head || !head->next){
            return head;
        }
		
        //declare temp nodes
        ListNode* dummy = new ListNode(0, head);    //for return
        ListNode* prev = dummy;                 //previous node
        ListNode* cur = head;                   //current node
        
        while(cur && cur->next){            //Iterate until all pairs are swapped (no next node/pair)
            //previous node assign to next current node (for pointing at the first node after swap)
            prev->next = cur->next;
            //next current node assign to next next current (for pointing at the next pair after swap)
            cur->next = cur->next->next;
            //the second node in pair pointing at the first node (for swap)
            prev->next->next = cur;
            
            //Now, all the next pointers are settled (swapped pair and the order is correct)
            //Therefore, we should update the temp nodes for the next iteration (next pair)
            prev = cur;             //prev move to the cur
            cur = prev->next;       //cur move one step forward
        }

        return dummy->next;
    }
};
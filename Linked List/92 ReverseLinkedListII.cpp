/*
https://leetcode.com/problems/reverse-linked-list-ii/
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
Example:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
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
    //Iterate solution (dummy), Time Complexity of O(n), Space Complexity of O(1)
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //declare temp nodes
        ListNode *dummy = new ListNode(0,head);         //dummy node that always pointing at head, for return
        ListNode *Leftprev = dummy;                     //the temp node for last node before reverse range
        ListNode *cur = head;                           //the node for reverse linked list

        //First Phase, move Leftprev and cur by iteration of m
        for(int i=1;i<m;i++){
            Leftprev = Leftprev->next;
            cur = cur->next;
        }
        //Now, cur is ready for reverse the linked list
        //Leftprev is ready for the reorder after the reverse

        ListNode *prev = NULL;                  //temp node for reverse a linked list
        //Second Phase, reverse the linked list in specified range(n-m+1)
        for(int i=1;i<=(n-m+1);i++){
            ListNode *tmp = cur->next;          //Assign temp node for saving next node
            cur->next = prev;                   //Reverse current node
            prev = cur;                         //Move previous node forward for next reverse
            cur = tmp;                          //Move current node forward for next reverse
        }
        
        //Now, the specified range in Linked List is reversed (dummy->1->2<-3<-4->5)
        //However, the order is not correct outside the range
        //Therefore, we should assign the next node of them by using temp node and the node after the reverse (Leftprev=1, prev=4 , cur=5 )
        Leftprev->next->next = cur;             //2->5
        Leftprev->next = prev;                  //1->4
        
        return dummy->next;
    }     
};
    //There is another solution by the use of Stack
    //We can push the value by original order in specified range into the stack.
    //Then, pop and assign the value back into the specified nodes in range.
    //However, this solution is argued that takes a extra memory of O(n-m) with stack storage.
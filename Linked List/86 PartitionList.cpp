/*
https://leetcode.com/problems/partition-list/
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
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
    //Iterate Solution, Time Complexity of O(n), Space Complexity of O(1)
public:
    ListNode* partition(ListNode* head, int x) {
        //Partition 2 new Linked List, the first part will be the nodes less than x, the second part will be greater than x
        ListNode *first = new ListNode(0);      //first part
        ListNode *second = new ListNode(0);     //second part
        ListNode *dummy = first;                //dummy node (for return or reference for next pointer) for first part
        ListNode *dummy2 = second;              //dummy node (for return or reference for next pointer) for second part
        
        while(head){                    //Iterate the Linked List to see if it is greater or less than x, then separate them into first/second part
            if (head->val < x){
                first->next = head;
                first = first->next;
            }else{
                second->next = head;
                second = second->next;
            }
            head = head->next;
        }
        
        second->next = NULL;            //Close the second part Linked List (closing pointer)
        first->next = dummy2->next;     //combine first part and second part
        return dummy->next;             //return the head node(dummy) of first part(first+second)
    }
};
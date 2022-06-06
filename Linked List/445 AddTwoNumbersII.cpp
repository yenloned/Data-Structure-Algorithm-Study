/*
https://leetcode.com/problems/add-two-numbers-ii/
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
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
    //Reverse Linked List Solution, Time Complexity of O(n+m), Space Complexity of O(max(n,m))
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //In this question, we should reverse both input list to let the carry value apply into the next node (the original previous node)
        //After the addition is finished, reverse the Linked List back to original order.

        //Reverse Linked List l1, please see "206 ReverseLinkedList.cpp"
        ListNode *temp1 = NULL;
        ListNode *prev1 = NULL;
        while(l1){
            temp1 = l1->next;
            l1->next = prev1;
            prev1 = l1;
            l1 = temp1;
        }
        
        //Reverse Linked List l2, please see "206 ReverseLinkedList.cpp"
        ListNode *temp2 = NULL;
        ListNode *prev2 = NULL;
        while(l2){
            temp2 = l2->next;
            l2->next = prev2;
            prev2 = l2;
            l2 = temp2;
        }
        
        //Add their values, please see "2 AddTwoNumbers.cpp"
        int v1, v2, carry, sum = 0;
        ListNode *l3 = new ListNode();
        ListNode *dummy = l3;               //remember to assign dummy node since l3 will be NULL after iteration
        while(prev1 || prev2 || carry){
            if (!prev1){
                v1 = 0;
            }else{
                v1 = prev1->val;
                prev1 = prev1->next;
            }
            if (!prev2){
                v2 = 0;
            }else{
                v2 = prev2->val;
                prev2 = prev2->next;
            }
            sum = v1 + v2 + carry;
            l3->next = new ListNode(sum%10);
            carry = sum/10;
            l3 = l3->next;
        }
        if (prev1){
            l3->next = prev1;
        }
        if (prev2){
            l3->next = prev2;
        }
        
        //Reverse Linked List l3 (with value added), please see "206 ReverseLinkedList.cpp"
        ListNode *temp3 = NULL;
        ListNode *prev3 = NULL;
        dummy = dummy->next;        //using dummy node
        while(dummy){
            temp3 = dummy->next;
            dummy->next = prev3;
            prev3 = dummy;
            dummy = temp3;
        }
        
        //Then return the reversed Linked List
        return prev3;
    }
};
    //There is another solution with the usage of stack. 
    //It takes shorter implementation and it can be argued that it is shorter in real time operation with same Time Complexity.
    //However, it takes extra memory with stack of O(m+n) which is greater than O(max(n,m))
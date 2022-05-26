/*
https://leetcode.com/problems/add-two-numbers/
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    //Iterative solution, Time Complexity of O(n), Space Complexity of O(n)
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode();  //the node for iteration
        ListNode *head = l3;            //the node for always pointing the head node
        
        int carry, v1, v2 = 0;
        //Iterate both input linked list and make sure the last carry is added
        while (l1 || l2 || carry){
            //Since the length of 2 linked list might not be the same, it should consider the case when one of them is NULL
            //Add them to declared variable if existed, 0 if not
            if (!l1){
                v1 = 0;
            }else{
                v1 = l1->val;
                l1 = l1->next;  //Now, l1 can move to next node for next iteration since it has no more usage.
            }
            if (!l2){
                v2 = 0;
            }else{
                v2 = l2->val;
                l2 = l2->next;  //Now, l2 can move to next node for next iteration since it has no more usage.
            }
            
            //combine the assigned variable to sum (value of l1 + value of l2 + the carry value assigned by last iteration)
            //the carry value in first iteration will be 0 by default(first declaration)
            int sum = v1 + v2 + carry;
            //create a new node then store the last digit of the assigned sum value. (That's why Space Complexity of O(n))
            //Then let the next node of l3 point to it
            l3->next = new ListNode(sum%10);
            carry = sum / 10;                   //assign carry value for the next iteration
            l3 = l3->next;                      //move the l3 to next node for the next iteration

        }
        
        return head->next;          //return the next node of head pointer (since all the value is assigned to the next node of l3)
    }
};
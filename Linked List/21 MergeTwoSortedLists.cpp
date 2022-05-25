/*
https://leetcode.com/problems/merge-two-sorted-lists/
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
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
    //Time Complexity of O(n); Space Complexity of O(1)
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //Create one node for the iteration(assign), one node for return(reference of the head node)
        ListNode *res = new ListNode();
        ListNode *dummy = new ListNode();
        //Make them share the same element
        dummy = res;
        
        //Since they are sorted, just compare them in the iteration
        while (list1 && list2){
            if (list1->val < list2->val){   //when list1 has smaller element, assign the next iterative node to list1
                res->next = list1;          //Now, the next node is pointing to the list1
                list1 = list1->next;        //Move one step forward for next iteration
            }else{
                res->next = list2;          //Similar approach when list2 smaller
                list2 = list2->next;        
            }
            res = res->next;            //When one iteration finish, the node for iteration move one step forward for next iteration
            //That's why we need to create a dummy node that always pointing at the head node, otherwise all the previous work will be gone.
        }
        
        //Edge case, one of the list could still have elements remain
        //Because only one of them will be not empty, we can assign the whole list instead of iterate the element one by one.
        if (list1){
            res->next = list1;
        }
        if (list2){
            res->next = list2;
        }
        
        //Return the next node of dummy since the first assigned node is from res->"next"
        return dummy->next;
    }
};
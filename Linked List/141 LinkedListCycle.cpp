/*
https://leetcode.com/problems/linked-list-cycle/
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    //Floyd Cycle solution, Time Complexity of O(n), Space Complexity of O(1)
public:
    bool hasCycle(ListNode *head) {
        //Base case, if there is no node, there will be no cycle
        if(head==NULL){
            return false;
        }
        
        //Floyd Cycle Detection Algorithm (a.k.a Tortoise and Hare Algorithm)
        //It contains two pointers, one move 1 step in each iteration while another one move 2 steps.
        //If it is a cycle, the two pointers will meet each other eventually.
        ListNode *slow = head;
        ListNode *fast = head;
        
        //To keep them in iteration, until they meet each other or NULL is detected
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            //return True when they met
            if (slow == fast){
                return true;
            }
        }
        
        //If the above iteration stopped without return, thats mean there is NULL in nodes, which must not be a cycle
        return false;
    }
};
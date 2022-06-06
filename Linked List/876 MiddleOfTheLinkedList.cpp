/*
https://leetcode.com/problems/middle-of-the-linked-list/
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
Example:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
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
    ListNode* middleNode(ListNode* head) {
        //In this solution, Tortoise and Hare Algorithm will be used.
        //When the fast pointer reach the end of the Linked List, the slow pointer will be at the position of middle
        ListNode *slow = head;
        ListNode *fast = head;
        
        //Iterate the Linked List with fast and slow pointers
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Return slow pointer
        return slow;
    }
};

    //In this question, there is another Brute Force solution with same Time Complexity and Space Complexity
    //It first get the length of the Linked List with O(n) iteration
    //Then, return the node that is at the middle position (length/2), which take another O(n/2)
    //Although it has the same Time Complexity and Space Complexity, it is argued that contains longer real time operation and longer implementation.
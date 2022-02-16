Swap Nodes in Pairs - Medium

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = head;
        ListNode* temp;
        if(head && head->next){
            ListNode* third = head->next->next;
            ans = head->next;
            temp = head;
            ans->next = temp;
            temp->next = third;
        }
        else{
            return head;
        }
        
        while(temp->next && temp->next->next){
            ListNode* back = temp->next->next->next;
            ListNode* second = temp->next->next;
            ListNode* first = temp->next;
            temp->next = second;
            second->next = first;
            first->next = back;
            temp = temp->next->next;
        }
        return ans;
    }
};
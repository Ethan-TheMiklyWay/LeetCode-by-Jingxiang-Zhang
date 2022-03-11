Rotate List
Medium

Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]


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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;  // length of the list
        ListNode *temp = head;
        
        while(temp){
            n++;
            if(!temp->next) break;
            temp = temp->next;
        }
        if(n<=1) return head;
        k = k%n;
        if(k==0) return head;
        
        temp->next = head; //make list circular
        
        temp = head;
        for(int i=0; i<n-k-1; ++i) temp = temp->next;
        head = temp->next;
        temp->next = nullptr;
        
        return head;
    
    }
};
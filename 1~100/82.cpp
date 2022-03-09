Remove Duplicates from Sorted List II - Medium


Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode first = ListNode(-100000);
        first.next = head;
        ListNode* now = &first;
        ListNode* last = &first;
        while(now){
            int value = now->val;
            bool flag = false;
            while(now->next && now->next->val == value){
                flag = true;
                ListNode* temp = now;
                now = now->next;
                delete temp;
            }
            if(flag){
                last->next = now->next;
            }
            else{
                last = now;
            }
            now = now->next;
        }
        return first.next;
    }
};
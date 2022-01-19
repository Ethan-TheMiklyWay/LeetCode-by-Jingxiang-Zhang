Linked List Cycle II  - Medium

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode* head) {/*
        int number=0;
        set<ListNode*> pointer_set;
        while(head){
            number++;
            pointer_set.insert(head);
            if(pointer_set.size()!=number) return head;
            head=head->next;
        }
        return NULL;
        */
        // suppose the list has a length n, and the circle length is m
        // S(slow) value take one step each time, and F(fast) take two steps
        // if S can meet F in the end, then assume S go for x steps,
        // F must go for (x + m) steps for an extra loop, and in the mean time,
        // F go (x * 2) steps. 
        // 2 x = x + m -> x = m, which means in the end, S and F would end up in the 
        // position m (the circle length). however the position we want is (n - m)
        // the we let S start over from 0, and F stay put. each time they go one
        // step. When finally they meet again, S would stand in the position of
        // (n - m) squarely, while F go (n - m) length, which would be 
        // m + (n - m) = n, and return to the starting point of the loop, which is 
        // (n - m), and they meet again.
        
        ListNode* fast=head,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }
       
        if(!fast || !fast->next) return nullptr;
        slow=head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
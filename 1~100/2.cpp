Add Two Numbers - Medium

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        ListNode* root = new ListNode();
        ListNode* current = root;
        ListNode* last;
        bool have1 = true;
        bool have2 = true;
        while(l1!=NULL || l2!=NULL){
            int v1 = 0;
            int v2 = 0;
            if(l1 != NULL) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                v2 = l2->val;
                l2 = l2->next;
            }
            
            int carry = 0;
            int sum = v1 + v2 + current->val;
            if(sum>=10){
                carry = 1;
                sum -= 10;
            }
            ListNode* temp = new ListNode(carry);
            current->val = sum;
            current->next = temp;
            last = current;
            current = temp;
        }
        if(current->val == 0){
            delete current;
            last->next = NULL;
        }
        return root;*/
        ListNode* root = new ListNode();
        ListNode* tail = root;
        int sum = 0;
        while(l1 || l2 || sum){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(sum%10);
            sum /= 10;
            tail = tail->next;
        }
        ListNode *temp = root->next;
        delete root;
        return temp;
        
    }
    
};
Merge k Sorted Lists - Hard
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* ans = new ListNode(-99999999);
        for(int i=0;i<lists.size();i++){
            merge(ans, lists[i]);
        }
        ListNode* temp = ans->next;
        delete ans;
        return temp;
    }
    
    void merge(ListNode* a, ListNode* b){
        ListNode* a_back = a;
        ListNode* a_temp = a;
        ListNode* b_temp = b;
        while(a_temp && b_temp){
            if(a_temp->val > b_temp->val){ // b insert in front of a
                ListNode* temp = b_temp;  // record b
                b_temp = b_temp->next;  // b move forward
                a_back->next = temp; // link a back into b
                temp->next = a_temp;  // link b into a
                a_back = temp;  // change a back into b
            }
            else{
                a_back = a_temp;  // a is smaller, then a move forward
                a_temp = a_temp->next;
            }
        }
        if(b_temp){
            a_back->next = b_temp;  // link all of b into a
        }
    }
    
    void show(ListNode* root){
        ListNode* temp = root;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
};

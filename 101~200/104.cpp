Maximum Depth of Binary Tree - Easy

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int current_dept = 0;
    int max_dept = 0;
    int maxDepth(TreeNode* root) {
        travel(root);
        return max_dept;
    }
    void travel(TreeNode* root){
        if(root){
            current_dept++;
            max_dept = max_dept>current_dept?max_dept:current_dept;
            travel(root->left);
            travel(root->right);
            current_dept--;
        }
    }
    
};
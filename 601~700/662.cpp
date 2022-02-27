Maximum Width of Binary Tree - Medium


Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3)


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
    
    int widthOfBinaryTree(TreeNode* root) {
        int result=1;
	    queue<pair<TreeNode*,int>> q;
	    q.push({root,0});
        while (!q.empty()) {
            int s=q.size(); // the size of current level nodes
            int current=0;
            for (int i=0; i<s; i++) { // all nodes in the current level
                pair<TreeNode*,long> p=q.front();
                q.pop();
                if(i==0) 
                    current=p.second; // the index of the leftmost node
                else 
                    result=result>(p.second-current+1)?
                            result:(p.second-current+1); // the distance
                if(p.first->left) 
                    q.push({p.first->left,p.second*2-current});
                if(p.first->right) 
                    q.push({p.first->right,p.second*2-current+1}); 
            }
        }
	return result;
    }
};
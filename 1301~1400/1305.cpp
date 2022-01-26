All Elements in Two Binary Search Trees - Medium

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]


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
    
    vector<int> sort_tree1;
    vector<int> sort_tree2;
    vector<int> result;
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        travel_tree1(root1);
        travel_tree2(root2);
        merge_tree();
        /*
        for(int i=0;i<sort_tree1.size();i++)
            cout<<sort_tree1[i]<<" ";
        cout<<endl;
        for(int i=0;i<sort_tree2.size();i++)
            cout<<sort_tree2[i]<<" ";
        cout<<endl;
        */
        return result;
    }
    
    void merge_tree(){
        int size1 = sort_tree1.size();
        int size2 = sort_tree2.size();
        int i = 0;
        int j = 0;
        while(i<size1 && j<size2){
            if(sort_tree1[i]<sort_tree2[j]){
                result.push_back(sort_tree1[i]);
                i++;
            }
            else{
                result.push_back(sort_tree2[j]);
                j++;
            }
        }
        while(i<size1){
            result.push_back(sort_tree1[i]);
            i++;
        }
        while(j<size2){
            result.push_back(sort_tree2[j]);
            j++;
        }
    }
    
    void travel_tree1(TreeNode *root){
        if(root){
            travel_tree1(root->left);
            sort_tree1.push_back(root->val);
            travel_tree1(root->right);
        }
    }
    void travel_tree2(TreeNode *root){
        if(root){
            travel_tree2(root->left);
            sort_tree2.push_back(root->val);
            travel_tree2(root->right);
        }
    }
        
};
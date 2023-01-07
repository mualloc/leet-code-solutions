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

// NOTE: **Balanced tree olmadığı zaman recursion'dan dolayı space complexity O(N) oluyor!!**
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(-2 == height(root)){
            return false;
        }
        return true;
    }
    
    int height(TreeNode* root){
        if(nullptr == root){
            return -1;
        }
        int leftHeight = height(root->left);   
        if(-2 == leftHeight){
            return -2;
        }
        int rightHeight = height(root->right);
        if(/*-2 == leftHeight ||*/ -2 == rightHeight){
            return -2;
        }
        if(abs(leftHeight - rightHeight) > 1){
            return -2;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};
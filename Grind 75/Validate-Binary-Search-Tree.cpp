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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode *prev = nullptr;
        while(false == stack.empty() || nullptr != root){
            while(nullptr != root){
                stack.push(root);
                root = root->left;
            }
            root = stack.top(); stack.pop();
            if(prev && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }  
        return true;
    }

    /*bool isValidBST(TreeNode* root) {
        if(nullptr == root) return true;
        if(false == isValidBST(root->left)) return false;
        if(nullptr != prev && prev->val >= root->val) return false;
        
        prev = root;      
        return isValidBST(root->right);
    }

private:
    TreeNode *prev = nullptr;*/
    
/*public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool isValidBSTHelper(TreeNode* root, long long int min, long long int max){
        if(nullptr == root) return true;
        
        if(root->val <= min || root->val >= max) return false;
                
        return isValidBSTHelper(root->left, min,  root->val) && isValidBSTHelper(root->right, root->val, max);  
    }*/
};
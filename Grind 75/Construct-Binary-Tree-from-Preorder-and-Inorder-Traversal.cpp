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


/******************************************************************************************
******************************************************************************************/
// NOTE, REVIEW THIS!!!!: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map
/******************************************************************************************
******************************************************************************************/


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stack({root});

        TreeNode *lastPopped = nullptr;
        for(int i = 1, j = 0; i < preorder.size(); ++i){
            while(false == stack.empty() && stack.top()->val == inorder[j]){
                lastPopped = stack.top(); stack.pop();
                j++;
            }
            TreeNode *curr = new TreeNode(preorder[i]);
            if(lastPopped){
                lastPopped->right = curr;
            }else{
                stack.top()->left = curr;
            }
            stack.push(curr);
            lastPopped = nullptr;
        } 
        
        return root;
    }
};


class Solution2 {
public:
    // TC: O(N), SC: O(N)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {        
        for(int i = 0; i < inorder.size(); i++) inorderIndices[inorder[i]] = i;
        int ps = 0;
        return buildTreeHelper(preorder, inorder, ps, 0, inorder.size() - 1);    
    }
    
private:
    TreeNode* buildTreeHelper(const vector<int>& preorder, const vector<int>& inorder, int & ps, int is, int ie) {
        if(is > ie) return nullptr;
        TreeNode *root = new TreeNode(preorder[ps]);
        
        int mid = inorderIndices[preorder[ps]];
        ps++;
        
        root->left = buildTreeHelper(preorder, inorder, ps, is, mid - 1);         
        root->right = buildTreeHelper(preorder, inorder, ps, mid + 1, ie);

        return root;
    }
  
    unordered_map<int, int> inorderIndices;
};
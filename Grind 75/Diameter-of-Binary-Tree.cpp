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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        stack<TreeNode*> stack;
        unordered_map<TreeNode*,int> heights;   // Also acts like visited array
        
        stack.push(root);
        while(false == stack.empty()){
            TreeNode* top = stack.top();
            
            if(nullptr != top->left && heights.end() == heights.find(top->left)) stack.push(top->left);
            else if(nullptr != top->right && heights.end() == heights.find(top->right)) stack.push(top->right);
            else{
                stack.pop();
                int leftHeight = nullptr == top->left ? -1 : heights[top->left];
                int rightHeight = nullptr == top->right ? -1 : heights[top->right];
                heights[top] = max(leftHeight, rightHeight) + 1;
                result = max(result, leftHeight + rightHeight + 2);
            }
        }
        return result;
    }
    
    /*int diameterOfBinaryTree(TreeNode* root) {
        diameterOfBinaryTreeHelper(root);
        return result;
    } 
    int diameterOfBinaryTreeHelper(TreeNode* root) {
        if(nullptr == root) return -1;
        int leftHeight = diameterOfBinaryTreeHelper(root->left);
        int rightHeight = diameterOfBinaryTreeHelper(root->right);
        result = max(result, leftHeight + rightHeight + 1 + 1); // left + right edge 
        return max(leftHeight, rightHeight) + 1;
    }    
private:
    int result = 0;*/
};
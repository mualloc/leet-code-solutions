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

// NOTE!!!!!!: Bunu anla: https://leetcode.com/problems/invert-binary-tree/discuss/62719/My-simple-recursion-java-solution
class Solution {
public:
    // Preorder recursion
    TreeNode* invertTree(TreeNode* root) {
        if(nullptr == root){
            return nullptr;
        }
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    
    // Recursive postorder
    /*TreeNode* invertTree(TreeNode* root) {
        if(nullptr != root){
            invertTree(root->left);
            invertTree(root->right);
            std::swap(root->left, root->right);  
        }     
        return root;
    }*/
   
    // DFS with stack
    /*TreeNode* invertTree(TreeNode* root) {
        std::stack<TreeNode*> stack;
        stack.push(root);
        while(false == stack.empty()){
            TreeNode *top = stack.top();
            stack.pop();
            if(nullptr != top){
                stack.push(top->left);
                stack.push(top->right);
                std::swap(top->left, top->right);
            }
        }
        return root;
    }*/
    
    // BFS with queue
    /*TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(false == queue.empty()){
            TreeNode* front = queue.front();
            queue.pop();
            if(nullptr != front){
                queue.push(front->left);
                queue.push(front->right);
                std::swap(front->left, front->right);
            }
        }
        return root;
    } */ 
};
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
    int minDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        if(nullptr == root->left) return 1 + minDepth(root->right);
        if(nullptr == root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        minDepthHelper(root, 0);
        return result;
    }
private:
    void minDepthHelper(TreeNode* root, int depth){
        if(nullptr == root) return;
        if(nullptr == root->left && nullptr == root->right) result = min(result, depth + 1);
        minDepthHelper(root->left, depth + 1);
        minDepthHelper(root->right, depth + 1);
    }
    int result = INT_MAX;
};

class Solution3 {
public:
    int minDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        queue<TreeNode*> todo({root});
        int result = 0;
        while(false == todo.empty()){
            ++result;
            int todoSize = todo.size();
            while(todoSize--){
                TreeNode* node = todo.front(); todo.pop();
                if(node->left) todo.push(node->left);
                if(node->right) todo.push(node->right);
                if(nullptr == node->left && nullptr == node->right) return result;
            }
        }
        return -1;      // This line never executes
    }
};

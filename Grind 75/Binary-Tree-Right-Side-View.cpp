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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightSideViewHelper(root, 0, result);
        return result;
    }
    
private:
    void rightSideViewHelper(TreeNode* root,int depth, vector<int> & result){
        if(nullptr == root) return;
        if(result.size() == depth) result.push_back(root->val);
        
        rightSideViewHelper(root->right, depth + 1, result);
        rightSideViewHelper(root->left, depth + 1, result);
    }
};

class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        result.reserve(kNumberOfNodes);
        if(nullptr == root) return result;
        queue<TreeNode*> queue;
        queue.push(root);
     
        while(false == queue.empty()){
            int qSize = queue.size();
            TreeNode* right = nullptr;
            while(qSize--){
                right = queue.front(); queue.pop();
                if(right->left) queue.push(right->left);
                if(right->right) queue.push(right->right);
            }
            result.push_back(right->val);
        }
        
        return result;
    }
    
private:
    enum SizeLimits{
        kNumberOfNodes = 101,
    };
};
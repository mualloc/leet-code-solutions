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
    // TC: O(N)
    // SC: O(N)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(nullptr == root) return result;
        queue<TreeNode*> todo({root});
        while(false == todo.empty()){
            const int todoSize = todo.size();
            result.push_back(vector<int>(todoSize));
            for(int i = 0; i < todoSize; ++i){
                TreeNode* node = todo.front(); todo.pop();
                result.back()[i] = node->val;
                if(node->left) todo.emplace(node->left);
                if(node->right) todo.emplace(node->right);
            }
            // Flip the order if level index is even
            if(!(result.size() & 1)) reverse(result.back().begin(), result.back().end());
        }
        return result;
    }
};

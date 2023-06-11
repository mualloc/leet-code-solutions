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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    void dfs(TreeNode* root, int level, vector<vector<int>>& result){
        if(nullptr == root) return;
        if(result.size() == level) result.push_back({});
        result[level].push_back(root->val);
        dfs(root->left, level + 1, result);
        dfs(root->right, level + 1, result);
    }
};


class Solution2 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(nullptr == root) return result;
        queue<TreeNode*> todo({root});
        while(false == todo.empty()){
            int todoSize = todo.size();
            result.push_back({});
            while(todoSize--){
                TreeNode* node = todo.front(); todo.pop();
                result.back().push_back(node->val);
                if(node->left) todo.emplace(node->left);
                if(node->right) todo.emplace(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

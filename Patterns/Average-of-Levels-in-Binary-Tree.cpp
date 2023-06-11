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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<long, int>> levelSumNodeCounts;
        dfs(root, 0, levelSumNodeCounts);
        vector<double> result(levelSumNodeCounts.size());
        for(int i = 0; i < levelSumNodeCounts.size(); ++i) result[i] = static_cast<double>(levelSumNodeCounts[i].first) / levelSumNodeCounts[i].second;
        return result;
    }
private:
    void dfs(TreeNode* root, int level, vector<pair<long, int>>& levelSumNodeCounts){
        if(nullptr == root) return;
        if(level == levelSumNodeCounts.size()) levelSumNodeCounts.push_back({});
        levelSumNodeCounts[level].first += root->val;
        ++levelSumNodeCounts[level].second;
        dfs(root->left, level + 1, levelSumNodeCounts);
        dfs(root->right, level + 1, levelSumNodeCounts);
    }
};


class Solution2 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> todo({root});
        vector<double> result;
        while(false == todo.empty()){
            long levelSum = 0;
            int todoSize = todo.size();
            const int levelSize = todo.size();
            while(todoSize--){
                TreeNode* node = todo.front(); todo.pop();
                levelSum += node->val;
                if(node->left) todo.push(node->left);
                if(node->right) todo.push(node->right);
            }
            result.push_back(static_cast<double>(levelSum) / levelSize);
        }
        return result;
    }
};

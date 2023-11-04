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
    // TC: O(N * log(N) * log(N))
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
private:
    void dfs(TreeNode* root, string curr, vector<string>& result) {
        if(nullptr == root) return;
        curr += (curr.size() ? "->" : "") + to_string(root->val);
        if(nullptr == root->left && nullptr == root->right) result.push_back(curr);
        else{
            dfs(root->left, curr, result);
            dfs(root->right, curr, result);
        }
    }
};

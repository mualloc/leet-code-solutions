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
    // TC: O(N^2) * Cost of copying the current path
    // TC Analysis: https://leetcode.com/problems/path-sum-ii/solutions/1382332/c-python-dfs-clean-concise-time-complexity-explained/
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> curr;
        pathSumHelper(root, targetSum, curr, result);
        return result;
    }
private:
    void pathSumHelper(TreeNode* root, int targetSum, vector<int>& curr, vector<vector<int>>& result){
        if(nullptr == root) return;
        curr.push_back(root->val);
        if(root->val == targetSum && !root->left && !root->right) result.push_back(curr);
        if(root->left) pathSumHelper(root->left, targetSum - root->val, curr, result);
        if(root->right) pathSumHelper(root->right, targetSum - root->val, curr, result);
        curr.pop_back();
    }
};

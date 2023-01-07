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
    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return maximum_path_sum_;
    }
    
    int maxPathSumHelper(TreeNode* root) {
        if(nullptr == root) return 0;
        int leftMax = max(0, maxPathSumHelper(root->left));
        int rightMax = max(0, maxPathSumHelper(root->right));
        maximum_path_sum_ = max(maximum_path_sum_, leftMax + rightMax + root->val);
        return root->val + max(leftMax, rightMax);
    }
     
private:
    int maximum_path_sum_ = INT_MIN;
};
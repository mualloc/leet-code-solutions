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

 // https://leetcode.com/problems/path-sum-iii/solutions/91878/17-ms-o-n-java-prefix-sum-method/comments/96424
class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> sums;  // Note long type!!
        int result = 0;
        pathSumHelper(root, targetSum, 0, sums, result);
        return result;
    }
private:
    void pathSumHelper(TreeNode* root, int targetSum, long currSum, unordered_map<long, int>& sums, int& result) {
        if(!root) return;
        if((currSum += root->val) == targetSum) ++result;
        if(sums.find(currSum - targetSum) != sums.end()) result += sums[currSum - targetSum];
        ++sums[currSum];
        pathSumHelper(root->left, targetSum, currSum, sums, result);
        pathSumHelper(root->right, targetSum, currSum, sums, result);
        if(0 == --sums[currSum]) sums.erase(currSum);
    }
};

class Solution2 {
public:
    // TC: O(N^2)
    // SC: O(N)
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSumHelper(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
private:
    int pathSumHelper(TreeNode* root, long int targetSum) {
        if(!root) return 0;
        return (root->val == targetSum) + pathSumHelper(root->left, targetSum - root->val) + pathSumHelper(root->right, targetSum - root->val);
    }
};

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

// https://leetcode.com/problems/maximum-binary-tree/solutions/106156/java-worst-case-o-n-solution/comments/143674
class Solution {
public:
    // TC: O(N)
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stack;
        for(const auto& num : nums){
            TreeNode *newNode = new TreeNode(num);
            while(false == stack.empty() && newNode->val > stack.back()->val){
                newNode->left = stack.back();
                stack.pop_back();
            }
            if(false == stack.empty()) stack.back()->right = newNode;
            stack.push_back(newNode);
        }
        return stack.front();
    }
};

class Solution2 {
public:
    // TC: O(N^2)
    // SC: O(N)   
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeHelper(nums, nums.cbegin(), nums.cend() - 1);
    }
private:
    TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, const vector<int>::const_iterator& begin, const vector<int>::const_iterator& end) {
        if(begin > end) return nullptr;
        auto max_it = max_element(begin, end + 1);
        TreeNode* root = new TreeNode(*max_it);
        root->left = constructMaximumBinaryTreeHelper(nums, begin, max_it - 1);
        root->right = constructMaximumBinaryTreeHelper(nums, max_it + 1, end);
        return root;
    }
};

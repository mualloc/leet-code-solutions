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

 // https://leetcode.com/problems/maximum-width-of-binary-tree/solutions/106645/c-java-bfs-dfs-3liner-clean-code-with-explanation/
class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    int widthOfBinaryTree(TreeNode* root) {
        vector<size_t> leftMostIndexes;
        return widthOfBinaryTreeHelper(root, 1, 0, leftMostIndexes);
    }
private:
    size_t widthOfBinaryTreeHelper(TreeNode* node, size_t index, int level, vector<size_t>& leftMostIndexes){
        if(nullptr == node) return 0;
        if(leftMostIndexes.size() == level) leftMostIndexes.push_back(index);
        return max(index - leftMostIndexes[level] + 1, max(widthOfBinaryTreeHelper(node->left, 2 * index, level + 1, leftMostIndexes), widthOfBinaryTreeHelper(node->right, 2 * index + 1, level + 1, leftMostIndexes)));
    }  
};

class Solution2 {
public:
    // TC: O(N)
    // SC: O(N)
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, size_t>> todo({make_pair(root, 1)});
        int result = 1;
        while(false == todo.empty()){
            int todoSize = todo.size();
            while(todoSize--){
                pair<TreeNode*, size_t> node = todo.front(); todo.pop();
                const size_t index = node.second << 1;
                if(node.first->left) todo.push({node.first->left, index});
                if(node.first->right) todo.push({node.first->right, index + 1});
            }
            int levelWidth = todo.size() > 0 ? todo.back().second - todo.front().second + 1 : 1;
            result = max(result, levelWidth);
        }
        return result;
    }
};

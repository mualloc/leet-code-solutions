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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        result.reserve(256);
        levelOrderHelper(root, result, 0);
        return result;
    }
private:
    void levelOrderHelper(TreeNode* root, vector<vector<int>> & result, int depth){
        if(root){
            if(result.size() <= depth){        
                result.push_back({});
            }
            result[depth].push_back(root->val);
            levelOrderHelper(root->left, result, depth + 1);
            levelOrderHelper(root->right, result, depth + 1);
        }
    }

    /*vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        result.reserve(InitialSizes::kUpper);    
        
        queue<TreeNode*> nodes;                 // Holds chilren in a level
        nodes.emplace(root);
        
        while(false == nodes.empty()){
            int countOfChildren = nodes.size();     // Count of nodes in a level
            result.push_back({});
            for(int i = 0; i < countOfChildren; i++){
                TreeNode* node = nodes.front(); nodes.pop();
                result.back().push_back(node->val);
                if(nullptr != node->left){
                    nodes.emplace(node->left);
                }
                if(nullptr != node->right){
                    nodes.emplace(node->right);
                }
            }
        }
        return result;
    }
private:
    enum InitialSizes{
        kUpper = 256            // Upper limit is 2000
    };*/
};
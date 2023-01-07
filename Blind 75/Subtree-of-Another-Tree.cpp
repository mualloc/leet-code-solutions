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
    // TC: O(R + S + R*S)       NOTE: string::find() is not linear!!!
    // SC: O(R + S)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rs, ss;
        buildString(root, rs);
        buildString(subRoot, ss);
        //cout << rs << endl;
        //cout << ss << endl;
        if (string::npos != rs.find(ss)) return true;
        else return false;
    }
    
private:
    // Preorder traversal
    void buildString2(TreeNode* root, string &s){
        if(nullptr == root) s += ",#";
        else{
            s += "," + std::to_string(root->val);
            buildString(root->left, s);                        
            buildString(root->right, s);
        }
    }
    
    // Postorder traversal 
    void buildString(TreeNode* root, string &s){
        if(nullptr == root) s += "#,";
        else{
            buildString(root->left, s);                        
            buildString(root->right, s);
            s += std::to_string(root->val) + ",";
        }
    }     
};


class Solution2 {
public:
    // TC: O(R + S)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        getHeight(root, getHeight(subRoot));
        
        for(const auto & candidate : candidates){
            if(isIdentical(candidate, subRoot)) return true;
        }
        return false;
    }
    
private:
    int getHeight(TreeNode* root, const int targetHeight = -1){
        if(nullptr == root) return -1;
        int height = max(getHeight(root->left, targetHeight), getHeight(root->right, targetHeight)) + 1;
        if(targetHeight == height) candidates.push_back(root);
        return height;
    }
    
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(!root || !subRoot) return !root && !subRoot;
        return root->val == subRoot->val && isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
    }
    
    vector<TreeNode*> candidates;
};


class Solution3 {
public:
    // TC: O(R * T)
    // SC: O(R)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(isIdentical(root, subRoot)) return true;
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    // TC: O(R * T)
    bool isSubtree2(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        stack<TreeNode*> stack({root});
        while(false == stack.empty()){
            TreeNode* top = stack.top(); stack.pop();
            if(isIdentical(top, subRoot)) return true;
            else if(top){
                stack.push(top->right);     
                stack.push(top->left);
            }
        }
        return false;
    }
    
    bool isSubtree3(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        queue<TreeNode*> queue({root});
        while(false == queue.empty()){
            TreeNode* front = queue.front(); queue.pop();
            if(isIdentical(front, subRoot)) return true;
            else if(front){
                queue.push(front->left);
                queue.push(front->right);     
            }
        }
        return false;
    }
    
private:
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(!root || !subRoot) return !root && !subRoot;
        return root->val == subRoot->val && isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
    }
};
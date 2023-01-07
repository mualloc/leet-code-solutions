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

// TC: O(h) --> For insertion, deletion and searching of kth. 
// (It will take O(n) time when we calculate the count value for the whole tree, but after that, it will take O(logn) time when insert/delete a node or calculate the kth smallest element.)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNodeWithCount *cRoot = createBSTWithNodeCount(root);
        return kthSmallestHelper(cRoot, k);
    }
    
private: 
    struct TreeNodeWithCount {
        TreeNodeWithCount(int x) : val(x), size(1) {}
        
        int val = 0;
        TreeNodeWithCount *left = nullptr;
        TreeNodeWithCount *right = nullptr;
        int size;
    };
    
    int kthSmallestHelper(TreeNodeWithCount* root, int k) {
        if(nullptr == root) return 0;     
        const int leftCount = root->left ? root->left->size : 0;
        if(k == leftCount + 1) return root->val;
        else if(k > leftCount + 1) return kthSmallestHelper(root->right, k - leftCount - 1);
        else return kthSmallestHelper(root->left, k);   // if(k <= root->left->size)       
    }

    TreeNodeWithCount* createBSTWithNodeCount(TreeNode* root){
        if(nullptr == root) return nullptr;
        TreeNodeWithCount *p = new TreeNodeWithCount(root->val);
        p->left = createBSTWithNodeCount(root->left);
        p->right = createBSTWithNodeCount(root->right);
        if(p->left) p->size += p->left->size;
        if(p->right) p->size += p->right->size;
     
        return p;
    }
};

class Solution3 {
public:
    // TC: O(H + k), SC: O(H)
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> todo;
        while(false == todo.empty() || nullptr != root){
            while(root){
                todo.push(root);
                root = root->left;
            }
            if(0 == --k) return todo.top()->val;
            root = todo.top()->right; todo.pop();       
        }
        return 0;
    }
};


class Solution4 {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestHelper(root, k);
    }
 
private:
    int kthSmallestHelper(TreeNode* root, int & k) {
        if(root){
            int result = kthSmallestHelper(root->left, k);
            if(result) return result;
            if(0 == --k) return root->val; 
            return kthSmallestHelper(root->right, k);
        }
        return 0;
    }     
};


class Solution5 {
public:
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestHelper(root, k);
        return result;
    }
    
private:
    void kthSmallestHelper(TreeNode* root, int & k){
        if(0 == result && root){
            kthSmallestHelper(root->left, k);
            if(0 == --k) {
                result = root->val;
                return;
            } 
            kthSmallestHelper(root->right, k);
        }
    }
    
    int result = 0;
};
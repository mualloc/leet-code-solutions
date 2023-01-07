/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        queue<TreeNode*> queue;
        queue.push(root);
        while(parent.end() == parent.find(p) || parent.end() == parent.find(q)){
            int queueSize = queue.size();
            while(queueSize--){
                TreeNode *front = queue.front(); queue.pop();
                if(front->right){
                    parent[front->right] = front;
                    queue.push(front->right);
                }
                if(front->left){
                    parent[front->left] = front;
                    queue.push(front->left);
                }
            }        
        }
        unordered_set<TreeNode*> pParents;
        while(p){
            pParents.insert(p);
            p = parent[p];
        }
        
        while(q && pParents.end() == pParents.find(q)){
            q = parent[q];
        }
        
        return q;
    }*/
    
    
    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stack;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        stack.push(root);
        
        while(parent.end() == parent.find(p) || parent.end() == parent.find(q)){
            TreeNode *top = stack.top(); stack.pop();
            if(top->right){
                parent[top->right] = top;
                stack.push(top->right);
            }
            if(top->left){
                parent[top->left] = top;
                stack.push(top->left);
            }
        }
        
        unordered_set<TreeNode*> pParents;
        while(p){
            pParents.insert(p);
            p = parent[p];
        }      
        while(pParents.end() == pParents.find(q)){
            q = parent[q];           
        }     
        return q;
    }*/
     
    // https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65225/4-lines-C%2B%2BJavaPythonRuby
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(nullptr == root || p == root || q == root) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
   
        if(left && right) return root;
        else  return left ? left : right;
    }
    
    // CtCI, p.260
    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(nullptr == root) return nullptr;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if(left != nullptr && p != left && q != left) return left;  // Already found ancestor
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(right != nullptr && p != right && q != right) return right;

        if(left && right){ // p and q found in diff. subtrees
            return root;    // This is the common ancestor
        }else if(p == root || q == root){
            return root;
        }else{
            return nullptr != left ? left : right;
        }  
    }*/
    
    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root) return root;
        
        if(search(root->left, p)){
            if(search(root->right, q)){
                return root;
            }else{
               return lowestCommonAncestor(root->left, p, q); 
            }
        }else{
            if(search(root->left, q)){
                return root;
            }else{
               return lowestCommonAncestor(root->right, p, q); 
            }  
        }
        
        return nullptr;
    }
    
private:
    bool search(TreeNode* root, TreeNode* node){
        if(nullptr == root) return false;       
        if(node == root) return true;
        return search(root->left, node) ||  search(root->right, node);
    }*/
};
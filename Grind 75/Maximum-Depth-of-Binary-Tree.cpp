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
    int maxDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        int result = 1;
        
        stack<TreeNode*> path({root});
        stack<int> depths({1});
        
        while(false == path.empty()){
            TreeNode* top = path.top(); path.pop();
            int depth = depths.top(); depths.pop();     
            result = max(result, depth);
 
            if(top->right){
                path.push(top->right);
                depths.push(depth + 1);
            }          
            if(top->left){
                path.push(top->left);
                depths.push(depth + 1); 
            }
        }        
        return result;
    }    
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        int result = 0;
        vector<TreeNode*> queue;    queue.reserve(1500);    int top = 0;
        queue.push_back(root);
        
        int remainCount = 0;
        while(queue.size() - remainCount){
            ++result;
            
            int currQueueSize = queue.size() - remainCount;
            remainCount += currQueueSize;
            while(currQueueSize--){
                TreeNode* front = queue[top++];
                if(front->left) queue.push_back(front->left);
                if(front->right) queue.push_back(front->right);               
            }
        }
        return result;
    }
};

class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        int result = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(false == queue.empty()){
            ++result;
            
            int currQueueSize = queue.size();          
            while(currQueueSize--){
                TreeNode* front = queue.front(); queue.pop();
                if(front->left) queue.push(front->left);
                if(front->right) queue.push(front->right);               
            }
        }
        return result;
    }
};

class Solution4 {
public:
    int maxDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution5 {
public:
    int maxDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        int result = 0;
        
        deque<TreeNode*> queue;
        queue.push_back(root);
        while(false == queue.empty()){
            ++result;
            
            int currQueueSize = queue.size();          
            while(currQueueSize--){
                TreeNode* front = queue.front(); queue.pop_front();
                if(front->left) queue.push_back(front->left);
                if(front->right) queue.push_back(front->right);               
            }
        }
        return result;
    }
};
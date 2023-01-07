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
    // TC: O(p + q)
    // SC: (min(p, q))
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> queue({{p, q}});
        while(false == queue.empty()){
            TreeNode* pFront = queue.front().first;
            TreeNode* qFront = queue.front().second;
            queue.pop();
            
            if(!pFront && !qFront) continue;
            else if(!pFront || !qFront) return false;   
            else if(pFront->val != qFront->val) return false;
            else{
                queue.push({pFront->left, qFront->left});
                queue.push({pFront->right, qFront->right});
            }
        } 
        return true;
    }
    
    bool isSameTree3(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> stack({{p, q}});        
        while(false == stack.empty()){
            TreeNode* pn = stack.top().first;
            TreeNode* qn = stack.top().second;
            stack.pop();
            
            if(!pn && !qn) continue;
            else if(!pn || !qn) return false;   
            else if(pn->val != qn->val) return false;
            else{
                stack.push({pn->left, qn->left});
                stack.push({pn->right, qn->right});
            }
        }
        return true;
    }
    
    bool isSameTree4(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pQueue({p});
        queue<TreeNode*> qQueue({q});
        
        while(false == pQueue.empty()){
            TreeNode* pFront = pQueue.front(); pQueue.pop();
            TreeNode* qFront = qQueue.front(); qQueue.pop();
            if(!pFront && !qFront) continue;
            else if(!pFront || !qFront) return false;   
            else if(pFront->val != qFront->val) return false;
            else{
                pQueue.push(pFront->left);
                pQueue.push(pFront->right);
                qQueue.push(qFront->left);
                qQueue.push(qFront->right);
            }
        } 
        return true;
    } 
};
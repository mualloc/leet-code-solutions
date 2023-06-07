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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, nullptr);       // Build unordered graph 

        unordered_set<int> visited;
        deque<int> todo{{target->val}};
        while(k-- > 0 && todo.size() > 0){
            int todoSize = todo.size();
            while(todoSize--){
                int node = todo.front(); todo.pop_front();
                visited.insert(node);
                for(int adj : graph[node]) if(visited.end() == visited.find(adj)) todo.push_back(adj);
            }
        }
        return {todo.begin(), todo.end()};
    }
private:
    void buildGraph(TreeNode* node, TreeNode* parent){
        if(nullptr == node) return;
        if(parent) graph[node->val].insert(parent->val);
        if(node->left) graph[node->val].insert(node->left->val);
        if(node->right) graph[node->val].insert(node->right->val);
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }
    
    unordered_map<int, unordered_set<int>> graph;
};

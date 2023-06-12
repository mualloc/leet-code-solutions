/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    Node* connect(Node* root) {
        if(nullptr == root) return nullptr;
        Node *cur = root, *nextLevel = root->left;
        while(nextLevel){
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
            if(nullptr == cur){
                cur = nextLevel;
                nextLevel = nextLevel->left;
            }
        }
        return root;
    }
};

class Solution2 {
public:
    // TC: O(N)
    // SC: O(N)
    Node* connect(Node* root) {
        if(nullptr == root) return nullptr;
        Node *left = root->left, *right = root->right, *next = root->next;
        if(left){
            left->next = right;
            if(next) right->next = next->left;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};

class Solution3 {
public:
    // TC: O(N)
    // SC: O(N)
    Node* connect(Node* root) {
        connectHelper(root, nullptr);
        return root;
    }
private:
    void connectHelper(Node* root, Node* right){
        if(nullptr == root) return;
        root->next = right;
        connectHelper(root->left, root->right);
        connectHelper(root->right, right ? right->left : nullptr);
    }
};

class Solution4 {
public:
    // TC: O(N)
    // SC: O(N)
    Node* connect(Node* root) {
        if(nullptr == root) return nullptr;
        queue<Node*> todo({root});
        while(false == todo.empty()){
            int todoSize = todo.size();
            while(todoSize--){
                Node* node = todo.front(); todo.pop();
                if(todoSize) node->next = todo.front();
                if(node->left) todo.emplace(node->left);
                if(node->right) todo.emplace(node->right);
            }
        }
        return root;
    }
};

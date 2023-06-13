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
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/solutions/472675/short-java-solution-with-explanation-100-runtime-and-100-memory/
class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    Node* connect(Node* root) {
        if(nullptr == root) return nullptr;
        if(root->left){
            if(root->right) root->left->next = root->right;
            else root->left->next = findNext(root->next);
        }
        if(root->right) root->right->next = findNext(root->next);
        connect(root->right);
        connect(root->left);
        return root;
    }
private:
    Node* findNext(Node* root){
        while(root){
            if(root->left) return root->left;
            if(root->right) return root->right;
            return findNext(root->next);
        }
        return nullptr;
    }
};

class Solution2 {
public:
    // TC: O(N)
    // SC: O(1)
    Node* connect(Node* root) {
        Node* curr = root;
        while(nullptr != curr){
            Node nextLevelStart;
            Node* last = &nextLevelStart;
            for(; nullptr != curr; curr = curr->next){
                if(curr->left) { last->next = curr->left; last = last->next; }
                if(curr->right) { last->next = curr->right; last = last->next; }
            }
            curr =  nextLevelStart.next;
        }
        return root;
    }
};

class Solution3 {
public:
    // TC: O(N)
    // SC: O(1)
    Node* connect(Node* root) {
        Node* curr = root;
        while(nullptr != curr){
            Node* nextLevelStart = nullptr;
            Node* last = nullptr;
            while(nullptr != curr){
                if(curr->left) {
                    if(nullptr == nextLevelStart) nextLevelStart = curr->left;
                    if(last) last->next = curr->left;
                    last = curr->left;
                }
                if(curr->right) {
                    if(nullptr == nextLevelStart) nextLevelStart = curr->right;
                    if(last) last->next = curr->right;
                    last = curr->right;
                }
                curr = curr->next;
            }
            curr = nextLevelStart;
        }
        return root;
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

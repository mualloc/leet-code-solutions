/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    /*Node* cloneGraph(Node* node) {
        if(nullptr == node) return nullptr;
        vector<Node*> nodesCloned(101,nullptr);
        //return DSClone(node, nodesCloned);
        //return BFClone(node, nodesCloned);
    }*/
    
    // https://leetcode.com/problems/clone-graph/discuss/42362/9-line-c%2B%2B-DFS-Solution
    Node* cloneGraph(Node* node){
        if(nullptr == node) return nullptr;
        if(map.find(node) == map.end()){
            map[node] = new Node(node->val);
            for(Node * neighbour : node->neighbors){
                map[node]->neighbors.push_back(cloneGraph(neighbour));
            }
        }
        return map[node];
    }
    
private:
    unordered_map<Node*, Node*> map;
        
    /*Node* DSClone(Node* node, vector<Node* > & nodesCloned){     
        Node *clonedNode = new Node(node->val);
        nodesCloned[node->val] = clonedNode;
    
        for( const auto & neighbor : node->neighbors){
            if(nullptr == nodesCloned[neighbor->val]){
                Node *newNode = DSClone(neighbor, nodesCloned);
            }
            clonedNode->neighbors.push_back(nodesCloned[neighbor->val]);  
        }
        
        return clonedNode;
    }*/
    /*Node* BFClone(Node* root, vector<Node* > & nodesCloned){   
        Node* result = new Node(root->val);
        nodesCloned[root->val] = result;
        
        queue<Node*> queue;
        queue.push(root);
        
        while(false == queue.empty()){
            Node *front = queue.front(); queue.pop();

            for(const auto & neighbour : front->neighbors){
                if(nullptr == nodesCloned[neighbour->val]){
                    // Cloning neighbour
                    nodesCloned[neighbour->val] = new Node(neighbour->val);
                    queue.push(neighbour);
                }
                nodesCloned[front->val]->neighbors.push_back(nodesCloned[neighbour->val]);
            }
        }
        return result;
    }*/
};
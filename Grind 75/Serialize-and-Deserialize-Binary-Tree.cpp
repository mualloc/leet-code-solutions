/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(nullptr == root) return "1001,";
        return std::to_string(root->val) + "," + serialize(root->left)  + serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        char* dataS = strdup(data.c_str());
        char* runner = dataS;
        vector<int> vals;

        while(*runner != '\0'){
            while(*runner != ',')   runner++;
            *runner = '\0';
            vals.push_back(atoi(dataS));
            dataS = ++runner;
        }
        int index = 0;
        return buildTree(vals, index);
    }
    
    TreeNode* buildTree(vector<int> & vals, int & index){
        if(vals.size() == index) return nullptr;
        int val = vals[index];
        
        ++index;
        if(1001 == val) return nullptr;
        
        TreeNode* root = new TreeNode(val);
        root->left = buildTree(vals, /*++*/index);
        root->right = buildTree(vals, /*++*/index);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
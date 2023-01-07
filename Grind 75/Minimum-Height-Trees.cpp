// REVIEW THIS: https://leetcode.com/problems/minimum-height-trees/discuss/76052/Two-O(n)-solutions
/*************************************************************************************************/
class Solution {
public:
    // TC: O(n)
    // https://leetcode.com/problems/minimum-height-trees/discuss/76052/Two-O(n)-solutions/79411
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(1 == n) return {0};
        vector<vector<int>> edgeList(n);
        for(const vector<int> & edge : edges){
            edgeList[edge[0]].push_back(edge[1]);
            edgeList[edge[1]].push_back(edge[0]);          
        }
        
        vector<int> pre(n, -1);
        int end1 = bfs(0, pre, edgeList);
        fill(pre.begin(), pre.end(), -1);
        int end2 = bfs(end1, pre, edgeList);
        
        vector<int> longestPath;
        while(end1 != end2){
            longestPath.push_back(end2);
            end2 = pre[end2];
        }
        longestPath.push_back(end2);
        
        if(longestPath.size() & 1) return {longestPath[longestPath.size() / 2]};        // If odd number of elements
        else return {longestPath[longestPath.size() / 2 - 1], longestPath[longestPath.size() / 2]};         
    }
    
private:
    int bfs(int start, vector<int> &pre, const vector<vector<int>> & edgeList){
        pre[start] = start;
        queue<int> queue({start});
        
        int result = -1;
        while(false == queue.empty()){
            int front = queue.front(); queue.pop();
            result = front;
            for(int neighbour : edgeList[front]){
                if(-1 == pre[neighbour]){
                    queue.push(neighbour);
                    pre[neighbour] = front;
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
    // TC: O(2n)
    // SC: O(3n)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(1 == n) return {0};
            
        vector<vector<int>> edgeList(n);
        vector<int> indegrees(n);
        for(const vector<int> & edge : edges){
            edgeList[edge[0]].push_back(edge[1]);
            edgeList[edge[1]].push_back(edge[0]);          
            ++indegrees[edge[0]], ++indegrees[edge[1]];
        }
        
        queue<int> leaves;
        for(size_t i = 0; i < indegrees.size(); ++i){
            if(1 == indegrees[i]) { leaves.push(i);  --indegrees[i]; }
        } 
        
        int remaining = n;
        while(remaining > 2){
            int qSize = leaves.size();
            remaining -= qSize;
            while(qSize--){
                int front = leaves.front(); leaves.pop();
                for(const int edge : edgeList[front]){
                    if(1 == --indegrees[edge]){
                        leaves.push(edge);
                    }
                }
            }
        }
        
        vector<int> result;
        while(false == leaves.empty()){
            result.push_back(leaves.front()); leaves.pop();  
        }           
        return result;
    }
};
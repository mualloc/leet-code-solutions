// Equivalent of Number of Connected Components in an Undirected Graph
class Solution {
public:
    // TC: O(n^2)
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        
        int result = 0;
        for(int i = 0; i < isConnected.size(); ++i){
            if(false == visited[i]){
                DFS(i, isConnected, visited);
                ++result;
            }
        }
        return result;
    }
    
private:
    void DFS(int i, vector<vector<int>>& isConnected, vector<bool> & visited){
        visited[i] = true;
        for(int j = 0; j < isConnected.size(); ++j){
            if(isConnected[i][j] && false == visited[j]) DFS(j, isConnected, visited);
        }
    }
};


class Solution2 {
public:
    // TC: O(n)
    // SC: O(n)
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> parent(isConnected.size(), 0);
        std::iota(parent.begin(), parent.end(), 0);
        vector<int> rank(isConnected.size(), 0);
        
        for(int i = 0; i < isConnected.size(); ++i){
            for(int j = 0; j <= i; ++j){
                if(isConnected[i][j]) union_(parent, rank, i, j);
            }
        }
        
        int result = 0;
        for(int i = 0; i < isConnected.size(); ++i) result += i == parent[i];
        return result;
    }
    
private:
    int find(vector<int> & parent, int city){
        if(parent[city] != city){
            parent[city] = find(parent, parent[city]);
            return parent[city];
        }
        return city;
    }
    
    void union_(vector<int> & parent, vector<int> & rank, int city1, int city2){
        city1 = find(parent, city1), city2 = find(parent, city2);
        if(city1 == city2) return;
        
        if(rank[city1] < rank[city2]) swap(city1,city2);
        parent[city2] = city1;
        if(rank[city1] == rank[city2]) ++rank[city1];
    }
};
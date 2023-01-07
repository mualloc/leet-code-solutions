#include <iostream>
#include <vector>
#include <list>

using namespace std;



class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        if(0 == n) return true;
        
        vector<list<int>> graph(n);
        for(const auto & edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        if(DetectCycle(0, graph, visited, -1)) return false;
        for(int i = 0; i < n; ++i) if(false == visited[i]) return false;
        return true;
    }

private:
    bool DetectCycle(int node, const vector<list<int>> & edges, vector<bool> & visited, int parent){
        visited[node] = true;

        for (auto it = edges[node].begin(); it != edges[node].end(); ++it){
            if(false == visited[*it]){
                if(true == DetectCycle(*it, edges, visited, node)) return true;
            }else if(parent != *it) return true;
        }  
        return false;
    }
};

/*void Test1(){
    Solution sol;
    vector<vector<int>> edges({{0, 1}, {0, 2}, {0, 3}, {1, 4}});
    if(true == sol.validTree(5, edges)) cout << "\nSUCCESS1" << endl;
    else cout << "\nFAIL1" << endl;
}

void Test2(){
    Solution sol;
    vector<vector<int>> edges({{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}});
    if(false == sol.validTree(5, edges)) cout << "\nSUCCESS2" << endl;
    else cout << "\nFAIL2" << endl;
}


int main()
{
    cout<<"Hello World" << endl;
    Test1();
    Test2();

    return 0;
}*/
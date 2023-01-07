class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visitStates(numCourses, 0);
        vector<int> * adj =  new vector<int>[numCourses];
        
        for(size_t i = 0; i < prerequisites.size(); i++){
            vector<int> & pre = prerequisites[i];
            adj[pre[0]].push_back(pre[1]);
        }   
        for(int i = 0; i < numCourses; i++){
            if(isCycle(i, adj, visitStates)) return false;
        }       
        return true;
    }
    
    bool isCycle(int i, vector<int> * adj, vector<int> & visitState){
        if(1 == visitState[i]) return true;
    
        if(0 == visitState[i]){
            visitState[i] = 1;
            for(int edge : adj[i]){
                if(true == isCycle(edge, adj, visitState)) return true;
            } 
        }
        visitState[i] = 2;     
        
        return false;
    }
    /*bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees = vector<int>(2000, 0);
        std::unordered_map<int,list<int>> edges;
        queue<int> queue;
        int count = 0;
        
        for(int i = 0; i < prerequisites.size(); i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegrees[prerequisites[i][0]]++;
        }
        
        for(size_t i = 0; i < numCourses; i++){
            if(0 == inDegrees[i] && edges.end() != edges.find(i)){
                queue.push(i);
            }
        }
        
        while(false == queue.empty()){
            count++;
            int front = queue.front(); queue.pop();

            for (list<int>::iterator it = edges[front].begin(); it != edges[front].end(); ++it){
                if(0 == --inDegrees[*it]){
                    queue.push(*it);
                }
            }        
        }
        return count == edges.size(); 
    }*/
    
    /*bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int> stack;
        vector<bool> visited = vector<bool>(2000, false);
        vector<list<int>> edges(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
    
        for(size_t i = 0; i < numCourses; i++){
            if(false == visited[i]){
                DFTopologicalSort(i, edges, visited, stack);
            }
        }
        
        return false == checkCycle(numCourses, edges, stack);   
    }
    
    // https://www.geeksforgeeks.org/detect-cycle-in-directed-graph-using-topological-sort/
    bool checkCycle(int numCourses, vector<list<int>> & edges, stack<int> & stack){
        unordered_map<int,int> pos;
        int index = 0;
        while(false  == stack.empty()){
            int top = stack.top(); stack.pop();
            pos[top] = index++;
        }
        
        for(size_t i = 0; i < numCourses; i++){
            list<int>  & edgeList = edges[i];
            for (list<int>::iterator it = edgeList.begin(); it != edgeList.end(); ++it){
                if(pos[i] >= pos[*it]){
                    return true;
                }
            }
        }
        return false;
    }
    
    void DFTopologicalSort(int n, vector<list<int>> & edges, vector<bool> & visited, stack<int> & stack){
        visited[n] = true;
                 
        for (list<int>::iterator it = edges[n].begin(); it != edges[n].end(); ++it){
            if(false == visited[*it]){
                DFTopologicalSort(*it, edges, visited, stack);
            } 
        }
        stack.push(n);
    }*/
};
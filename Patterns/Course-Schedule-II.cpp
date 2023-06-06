class Solution {
public:
    enum class VisitState : uint8_t {
        kUnvisited = 0,
        kVisiting,
        kVisited
    };
    // TC: O(N + P)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto& prerequisite : prerequisites) graph[prerequisite[1]].push_back(prerequisite[0]);
        vector<VisitState> visitStates(numCourses, VisitState::kUnvisited);
        vector<int> result;
        for(int node = 0; node < numCourses; ++node) {
            if(false == topologicalSort(node, graph, visitStates, result)) return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
private:
    bool topologicalSort(int node, const vector<vector<int>>& graph, vector<VisitState>& visitStates, vector<int>& result){
        if(VisitState::kVisiting == visitStates[node]) return false;
        if(VisitState::kVisited == visitStates[node]) return true;
        visitStates[node] = VisitState::kVisiting;
 
        const vector<int>& adjancencies = graph[node];
        for(int node : adjancencies) if(false == topologicalSort(node, graph, visitStates, result)) return false;
        
        visitStates[node] = VisitState::kVisited;
        result.push_back(node);
        return true;
    }
};

class Solution2 {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++indegrees[prerequisite[0]];
        }
        
        queue<int> todo;
        for(int i = 0; i < indegrees.size(); ++i) if(0 == indegrees[i]) todo.push(i);

        vector<int> result;
        while(false == todo.empty()){
            auto front = todo.front(); todo.pop();
            result.push_back(front);
            const vector<int>& adjancencies = graph[front];
            for(int node : adjancencies) if(0 == --indegrees[node]) todo.push(node);
        }

        return result.size() != numCourses ? vector<int>() : result;
    }
};

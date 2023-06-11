// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/solutions/1106701/c-two-level-topological-sort-peel-off-the-tricky-parts-then-do-normal-toposort/
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Assign dummy groups to non-grouped items
        for(int i = 0; i < group.size(); ++i) if(-1 == group[i]) group[i] = m++;

        // Build graphs and indegrees
        vector<unordered_set<int>> itemGraph(n), groupGraph(m);
        vector<int> itemIndegrees(n), groupIndegrees(m);
        for(int i = 0; i < n; ++i){
            for(int beforeItem : beforeItems[i]){
                itemGraph[beforeItem].insert(i);
                ++itemIndegrees[i];
                // Check if this predecessor group is added already to not to increment indegree incorrectly!!
                if(group[i] != group[beforeItem] && groupGraph[group[beforeItem]].end() == groupGraph[group[beforeItem]].find(group[i])){
                    groupGraph[group[beforeItem]].insert(group[i]);
                    ++groupIndegrees[group[i]];
                }
            }
        }
        //
        vector<int> sortedGroups = topologicalSort(groupGraph, groupIndegrees);
        vector<int> sortedItems = topologicalSort(itemGraph, itemIndegrees);
        if(0 == sortedGroups.size() || 0 == sortedItems.size()) return {};

        vector<vector<int>> sortedItemsDividantByGroup(m);
        for(int item : sortedItems) sortedItemsDividantByGroup[group[item]].push_back(item);
        
        vector<int> result;
        result.reserve(n);
        for(int sg : sortedGroups) move(sortedItemsDividantByGroup[sg].begin(), sortedItemsDividantByGroup[sg].end(), inserter(result, result.end()));
        sortedItemsDividantByGroup.clear();
        return result;
    }
private:
    vector<int> topologicalSort(const vector<unordered_set<int>>& graph, vector<int> indegrees){
        queue<int> todo;
        for(int i = 0; i < indegrees.size(); ++i) if(0 == indegrees[i]) todo.push(i);

        vector<int> result;
        while(false == todo.empty()){
            int node = todo.front(); todo.pop();
            result.push_back(node);
            for(int adjacent : graph[node]) if(0 == --indegrees[adjacent]) todo.push(adjacent);
        }

        return graph.size() == result.size() ? result : vector<int>();
    }
};

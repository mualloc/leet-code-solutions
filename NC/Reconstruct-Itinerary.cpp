// https://leetcode.com/problems/reconstruct-itinerary/solutions/375397/simply-simple-python-solution-using-stack-for-dfs-with-comments/
class Solution {
public:
    // TC: O(T)
    // SC: O(T)
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> routes;
        for(const auto& ticket : tickets) routes[ticket[0]].push(ticket[1]);

        vector<string> result;
        stack<string> stack{{"JFK"}};
        while(!stack.empty()) {
            // Check if elem in graph as there may be a case when there is no out edge from an airport
            if(auto it = routes.find(stack.top()); it != routes.end() && !it->second.empty()) {
                stack.push(it->second.top());
                it->second.pop();
            }else {
                result.push_back(stack.top());
                stack.pop();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


class Solution2 {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> routes;
        for(const auto& ticket : tickets) routes[ticket[0]].push_back(ticket[1]);
        for(auto& dests : routes) sort(dests.second.begin(), dests.second.end());
        vector<string> result{"JFK"};
        reconstruct(routes, tickets.size() + 1, result);
        return result;
    }
private:
    bool reconstruct(unordered_map<string, vector<string>>& routes, const int target, vector<string>& result) {
        if(target == result.size()) return true;
        for(auto& dest : routes[result.back()]) {
            if('_' != dest.back()) {
                result.push_back(dest);
                dest.push_back('_');
                if(reconstruct(routes, target, result)) return true;
                dest.pop_back();
                result.pop_back();
            }
        }
        return false;
    }
};

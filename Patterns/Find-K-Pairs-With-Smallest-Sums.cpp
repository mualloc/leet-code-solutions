class Solution {
public:
    // TC: O(k * logk)
    // SC: O(k)
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1 = static_cast<const vector<int>&>(nums1), &nums2 = static_cast<const vector<int>&>(nums2)] (const auto& p1, const auto& p2) {return nums1[p1.first] + nums2[p1.second] >= nums1[p2.first] + nums2[p2.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(auto i{0}; i < nums1.size() && i < k; ++i)  pq.emplace(i, 0);
		
        vector<vector<int>> result;
        while(k-- && !pq.empty()){
            auto [u, v] = pq.top();  pq.pop();
            result.push_back({nums1[u], nums2[v]});
            if(++v < nums2.size()) pq.push({u, v});
        }
        return result;
    }
};

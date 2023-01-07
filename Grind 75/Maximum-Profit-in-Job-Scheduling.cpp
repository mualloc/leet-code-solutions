class Solution {
public:
    // Bottom-up DP
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;     
        for(size_t i = 0; i < startTime.size(); i++)    jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end(), [](const auto & v1, const auto & v2) {return v1[0] < v2[0];});
        
        vector<int> dp(jobs.size());
        dp[jobs.size() - 1] = jobs[jobs.size() - 1][2];      
        for(int i = jobs.size() - 2; i >= 0; --i){
            int next = findNext(i, jobs);
            dp[i] = max(dp[i + 1], jobs[i][2] + (-1 != next ? dp[next] : 0));
        }

        return dp[0];
    }    
    
    // Top-down DP (Memoization). TC:  O(N^2) or O(N*logN) depending on findNext implementation
    int jobScheduling2(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;     
        for(size_t i = 0; i < startTime.size(); i++)    jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end(), [](const auto & v1, const auto & v2) {return v1[0] < v2[0];});
        
        unordered_map<int, int> dp;
        return dfs(0, jobs, dp);
    }
    
private:
    int dfs(int i, const vector<vector<int>> & jobs, unordered_map<int, int> & dp){
        if(i >= jobs.size() || i < 0) return 0;
        if(dp.find(jobs[i][0]) != dp.end()) return dp[jobs[i][0]];
        
        int next = findNext(i, jobs);
        int inclProfit = jobs[i][2] + (-1 != next ? dfs(next, jobs, dp) : 0);
        int exclProfit = dfs(i + 1, jobs, dp);
        
        return dp[jobs[i][0]] = max(inclProfit, exclProfit);
    }
    
    int findNext(int currIndex, const vector<vector<int>>& jobs){
        int result = -1;
        
        int currEnd = jobs[currIndex][1];
        int low = currIndex + 1;
        int high = jobs.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(jobs[mid][0] < currEnd) low = mid + 1;
            else {
                result = mid;
                high = mid - 1;
            }
        }   
        return result;        
    }
    
    int findNext2(int currIndex, const vector<vector<int>>& jobs){
        int currEnd = jobs[currIndex][1];
        for(int i = currIndex + 1; i < jobs.size(); i++){
            if(jobs[i][0] >= currEnd) return i;
        }
        return -1;
    }
};


class Solution2 {
public:
    // Sort by end time
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;     
        for(size_t i = 0; i < startTime.size(); i++)    jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end(), [](const auto & v1, const auto & v2) {return v1[1] < v2[1];});
        
        map<int, int> dp({make_pair(0,0)});
        for(const auto & job : jobs){  
            int currProfit = prev(dp.upper_bound(job[0]))->second + job[2];
            if(currProfit > dp.rbegin()->second) dp[job[1]] = currProfit;
        }
        return dp.rbegin()->second;
    }
};


class Solution3 {
public:
    // Sort by end time
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;     
        for(size_t i = 0; i < startTime.size(); i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const auto & v1, const auto & v2) {return v1[1] < v2[1];});
        
        vector<int> dp(jobs.size());
        dp[0] = jobs[0][2];
        
        for(int i = 1; i < jobs.size(); i++){
            int index = findPrev(i - 1, jobs, jobs[i][0]);
            if(-1 == index) dp[i] =  max(dp[i - 1], jobs[i][2]);
            else{
                dp[i] =  max(dp[i - 1], dp[index] + jobs[i][2]);
            }
        }
                
        return dp.back();
    }

private:
    int findPrev(int high, const vector<vector<int>>& jobs, int startTime){
        int low = 0;
        int result = -1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(jobs[mid][1] > startTime) high = mid - 1;
            else {
                result = mid;
                low = mid + 1;
            }
        }   
        return result;
    }
    
    int findPrev2(int rStart, const vector<vector<int>>& jobs, int startTime){
        for(int i = rStart; i >= 0; --i){
            if(jobs[i][1] <= startTime) return i;
        }
        return -1;
    }
};
class Solution {
public:
    // TC: O(TS)
    // SC: O(26)
    int leastInterval(vector<char>& tasks, int n) {
        int count = 0, maxCount = 0;
        vector<int> tasksCount(26);    
        for(const char task : tasks) {
            if(++tasksCount[task - 'A'] > count) {
                count = tasksCount[task - 'A'];
                maxCount = 1;
            }else if(tasksCount[task - 'A'] == count) {++maxCount;}
        } 
        return std::max((int)tasks.size(), (n + 1) * (count - 1) + maxCount);
    } 
};



class Solution2 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(0 == n) return tasks.size();
        vector<int> tasksCount(26);    
        for(const char task : tasks)  ++tasksCount[task - 'A'];
        tasksCount.erase(std::remove(tasksCount.begin(), tasksCount.end(), 0), tasksCount.end());
        priority_queue<int> pq(tasksCount.begin(), tasksCount.end());
                          
        int result = 0;
        while(false == pq.empty()){       
            vector<int> tempList;
            int idleTime = n + 1;   // Period
            while(false == pq.empty() && idleTime > 0){
                tempList.push_back(pq.top());  pq.pop();
                ++result;
                idleTime--;
            }
            for(int temp : tempList){
                if(--temp) pq.push(temp);
            }       
            
            if(true == pq.empty()) break;
            // NOTE: Idle time is not  added  when pq is empty!!
            result += idleTime;       
        }
        
        return result;
    }
};



class Solution3 {
public:
    // TC: O(m * n)
    // SC: O(26)
    // NOTE: https://leetcode.com/problems/task-scheduler/discuss/104501/Java-PriorityQueue-solution-Similar-problem-Rearrange-string-K-distance-apart/230488
    int leastInterval(vector<char>& tasks, int n) {
        if(0 == n) return tasks.size();
        vector<int> tasksCount(26);    
        for(const char task : tasks)  ++tasksCount[task - 'A'];
        tasksCount.erase(std::remove(tasksCount.begin(), tasksCount.end(), 0), tasksCount.end());
        priority_queue<int> pq(tasksCount.begin(), tasksCount.end());
        queue<pair<int, int>> rest; // count, available time
        
        int result = 0;
        while(pq.size() || rest.size()){
            if(pq.size()){
                int top = pq.top(); pq.pop();
                if(--top) rest.push({top, result + n});
            }  
            if(rest.size() > 0 && rest.front().second == result){
                int front = rest.front().first; rest.pop();
                pq.push(front);
            }
            ++result;
        }
        return result;
    }
};
class Solution {
public:
    // O(N + klogN): The N part is on adding all points to the heap (building a min heap for all the points) and the klogN part is on fetching the top k points from the heap.
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Squared distance, index in points
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQueue;
        
        vector<vector<int>> result;
        for(size_t i = 0; i < points.size(); i++){
            vector<int> & point = points[i];
            int squaredDistance = distanceSquare(point[0], point[1]); 
            pQueue.emplace(squaredDistance, i);
        }
        for(size_t i = 0; i < k; i++){
            pair<int, int> top = pQueue.top(); pQueue.pop();
            size_t index = top.second;
            result.push_back(points[index]);
        }     
        return result;
    }
    
    // O(Nlogk)
    /*vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Squared distance, index in points
        priority_queue<pair<int, int>> pQueue;
        vector<vector<int>> result;
               
        for(size_t i = 0; i < points.size(); i++){
            vector<int> point = points[i];
            int squaredDistance = distanceSquare(point[0], point[1]);
            if(pQueue.size() < k){
                pQueue.emplace(squaredDistance, i);
            }else{
                pair<int, int> top = pQueue.top();
                int topDistance = top.first;
                if(squaredDistance < topDistance){
                    pQueue.pop();
                    pQueue.emplace(squaredDistance, i);
                }
            }
        }
        while(false == pQueue.empty()){
            pair<int, int> top = pQueue.top(); pQueue.pop();
            size_t index = top.second;
            result.push_back(points[index]);
        }
        return result;
    }*/
    
    private:
    int distanceSquare(int x, int y){
        return x * x + y * y;
    }
};
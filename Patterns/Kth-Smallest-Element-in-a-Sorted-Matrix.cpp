class Solution {
public:
    // https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1321862/python-binary-search-solution-explained/comments/1004090
    // TC: O(n * log(max - min))
    // SC: O(1)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0], high = matrix.back().back();
        while(low < high){
            int mid = low + ((high - low) >> 1);
            int countOfElementsLeq = findCountOfNumbersLeq(matrix, mid);
            if(countOfElementsLeq >= k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
private:
    int findCountOfNumbersLeq(const vector<vector<int>>& matrix, int element){
        const int len = matrix.size();
        int result = 0;
        for(int i = 0, j = len - 1; i < len; ++i){
            while(j >= 0 && matrix[i][j] > element) --j;
            result += j + 1;
        }
        return result;
    }
};

class Solution2 {
public:
    // TC: O(k*logk)
    // SC: O(k)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        const int n = matrix.size();
        const int queueSize = min(k, n);    // Note this!!
        for(int i = 0; i < queueSize; ++i) minHeap.push({matrix[i][0], i, 0});
        
        while(--k){
            auto top = minHeap.top(); minHeap.pop();
            int row = top[1], col = top[2];
            if(col + 1 < n) minHeap.push({matrix[row][col + 1], row, col + 1});
        }

        return minHeap.top()[0];
    }
};

class Solution3 {
public:
    // TC: O(n*n*logk)
    // SC: O(k)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;
        for(const auto& row : matrix){
            for(const auto& element : row){
                maxHeap.push(element);
                if(k + 1 == maxHeap.size()) maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

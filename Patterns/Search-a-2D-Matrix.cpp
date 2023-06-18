class Solution {
public:
    // TC: O(log(m) + log(n))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(),  n = matrix[0].size();
        int top = 0, bottom = m - 1;
        int row = -1;
        while(top <= bottom){
            int mid = top + ((bottom - top) >> 1);
            if(target > matrix[mid].back()) top = mid + 1;
            else if(target < matrix[mid].front()) bottom = mid - 1; 
            else {
                row = mid;
                break;
            }
        }
        if(-1 == row) return false;
        const vector<int>& nums = matrix[row];
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(target == nums[mid]) return true;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

class Solution2 {
public:
    // TC: O(log(m * n)) = O(log(m) + log(n))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(),  n = matrix[0].size();
        int low =  0, high = m * n - 1;
        int mid = low + ((high - low) >> 1);
        int row = mid / n;
        int col = mid % n;
        do{
            if(target == matrix[row][col]) return true;
            else if(matrix[row][col] > target) high = mid - 1;
            else low = mid + 1;
            mid = low + ((high - low) >> 1);
            row = mid / n;
            col = mid % n;
        }while(low <= high);

        return false;
    }
};

class Solution3 {
public:
    // TC: O(m + n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        for(int row = 0; row < m; ++row){
            if(target <= matrix[row].back()) {
                for(const int num : matrix[row]) if(target == num) return true;
                break;
            }
        }
        return false;
    }
};

class Solution4 {
public:
    // TC: O(m + n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size() - 1, row = 0;
        while(col >= 0 && row < matrix.size()){
            if(target == matrix[row][col]) return true;
            else if(target > matrix[row][col]) ++row;
            else --col;
        }
        return false;
    }
};

// RECURSIVE SOLUTION: https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/66147/java-an-easy-to-understand-divide-and-conquer-method/comments/429310


// https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/66139/c-search-from-top-right/
class Solution {
public:
    // TC: O(m + n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while(row < matrix.size() && col >= 0){
            if(target > matrix[row][col]) ++row;
            else if(target < matrix[row][col]) --col;
            else return true;
        }
        return false;
    }
};

class Solution2 {
public:
    // TC: O(m + n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1, col = 0;
        while(row >= 0 && col < matrix[0].size()){
            if(target > matrix[row][col]) ++col;
            else if(target < matrix[row][col]) --row;
            else return true;
        }
        return false;
    }
};

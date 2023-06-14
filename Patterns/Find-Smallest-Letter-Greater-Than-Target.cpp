class Solution {
public:
    // TC: O(logN)
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.front() > target || letters.back() <= target) return letters.front();
        int low = 0, high = letters.size() - 1;
        while(low + 1 < high){
            int mid = low + (high - low) / 2;
            if(letters[mid] <= target) low = mid;
            else high = mid;
        }
        return letters[high];
    }
};


class Solution2 {
public:
    // TC: O(logN)
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.front() > target || letters.back() <= target) return letters.front();
        int low = 0, high = letters.size() - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(letters[mid] <= target) low = mid + 1;
            else high = mid;
        }
        return letters[low];
    }
};

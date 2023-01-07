class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int start = 0, end = height.size() - 1;
        while(start < end){
            int lower = min(height[start], height[end]);
            result = max(result, lower * (end - start));
            while(start < end && height[start] <= lower) ++start;
            while(start < end && height[end] <= lower) --end;
        }
        return result;
    }
};
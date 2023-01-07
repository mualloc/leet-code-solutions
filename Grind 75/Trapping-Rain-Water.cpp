class Solution {
public:
    // https://leetcode.com/problems/trapping-rain-water/discuss/17391/Share-my-short-solution.
    int trap(vector<int>& height) {
        int result = 0;
        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right];
        
        // use two pointers to scan the entire array until they meet with each other
        // Key points: any bars in the middle of leftMax bar and rightMax bar will not influence
        // how much water can current position trap
        while(left < right){
            if(maxLeft < maxRight){
                left++;
                maxLeft = max(maxLeft, height[left]);
                result += maxLeft - height[left];
            }else{
                right--;
                maxRight = max(maxRight, height[right]);  
                result += maxRight - height[right];
            }
        }      
        return result;
    }
    
/*public:
    int trap(vector<int>& height) {
        int result = 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        
        for(int i = 1; i < height.size(); i++){
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }      
        for(int i =  height.size() - 2; i >= 0; --i){
            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
        } 
        for(int i = 0; i < height.size(); i++){
            int temp = min(maxLeft[i], maxRight[i]) - height[i] ;
            if(temp > 0) result += temp;
        }
        return result;
    }*/
};
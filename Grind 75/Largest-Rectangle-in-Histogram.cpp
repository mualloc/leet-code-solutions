/*** NlogN Segment Tree Solution:
https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28941/Segment-tree-solution-just-another-idea-O(N*logN)-Solution
***/
///////*******************************************************************************///////
/*** Simple Divide and Conquer AC solution without Segment Tree
https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28910/Simple-Divide-and-Conquer-AC-solution-without-Segment-Tree
***/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> lessFromLeft(heights.size());
        vector<int> lessFromRight(heights.size());
        lessFromLeft[0] = -1;
        lessFromRight[lessFromRight.size() - 1] = heights.size();
        
        for(int i = 1; i < heights.size(); i++){
            int previous = i - 1;
            while(previous >= 0 && heights[previous] >= heights[i]){
                previous = lessFromLeft[previous];
            }
            lessFromLeft[i] = previous;
        }
        for(int i = heights.size() - 2; i >= 0; i--){
            int next = i + 1;
            while(next < heights.size() && heights[next] >= heights[i]){
                next = lessFromRight[next];
            }
            lessFromRight[i] = next;
        }
                
        int result = 0;
        for(int i = 0; i < heights.size(); i++){
            result = max(result, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        }
        return result;
    }
};


class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        //heights.push_back(0); // This is added to avoid unprocessed heights in main loop

        stack<int> stack;   // indexes
        for(int i = 0; i <= heights.size(); ++i){
            int currHeight = i ==  heights.size() ? 0 : heights[i];
            while(false == stack.empty() && heights[stack.top()] > currHeight){
                int topHeight = heights[stack.top()]; stack.pop();
                int width = i - (stack.empty() ? -1 : stack.top()) - 1;
                result = max(result, width * topHeight);
            }
            stack.push(i);
        }   
        return result;
    }
};
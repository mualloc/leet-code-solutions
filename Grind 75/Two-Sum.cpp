#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        unordered_map<int,size_t> elementIndexMap((nums.size()));
        
        for(size_t i=0;i<nums.size();i++)
        {
            int num = nums[i];
            if (elementIndexMap.find(target - num) != elementIndexMap.end())
            {
                result.push_back(elementIndexMap[target - num]);
                result.push_back(i);
                break;
            }
            else{
                elementIndexMap[num] = i;
            }
        }
        return result;
    }
};
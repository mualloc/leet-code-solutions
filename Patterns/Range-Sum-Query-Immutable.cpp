class NumArray {
public:
    NumArray(vector<int>& nums) : prefix_(nums) {
        for(int i = 1; i < nums.size(); ++i) prefix_[i] = prefix_[i - 1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left - 1 < 0) return prefix_[right];
        return prefix_[right] - prefix_[left - 1];
    }
private:
    vector<int> prefix_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
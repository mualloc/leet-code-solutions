class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;   // Right index of 0s
        int mid = 0;    // Right index of 0s and 1s
        
        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            nums[i] = 2;
            if(temp < 2){
               nums[mid++] = 1;
            }
            if(0 == temp){
                nums[left++] = 0;
            }
        }
    }
    /*void sortColors(vector<int>& nums) {
        int i = 0, left = 0, right = nums.size() - 1;
        
        while(i <= right){
            if(0 == nums[i])  swap(nums[i++], nums[left++]);
            else if(2 == nums[i]) swap(nums[i], nums[right--]);
            else i++;
        }
    }*/
    
    /*void sortColors(vector<int>& nums) {
		quickSort(0, nums.size() - 1, nums);
	}
    
private:	
	void quickSort(int low, int high, vector<int>& nums){
		if(low < high){
			int pi = partition(low, high, nums);
			quickSort(low, pi - 1, nums);
			quickSort(pi + 1, high, nums);
		}
	}
	
	int partition(int low, int high, vector<int>& nums){
		int separator = low - 1;
		
		for( ; low < high; low++){
			if(nums[low] < nums[high])   swap(nums[++separator], nums[low]);	
		}
		swap(nums[++separator], nums[high]);
		return separator;
	}*/
};
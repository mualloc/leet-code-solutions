// https://leetcode.com/problems/find-k-closest-elements/solutions/106426/java-c-python-binary-search-o-log-n-k-k/
class Solution {
public:
    // TC: O(log(N-k) + k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while(left < right){
            int mid = left + ((right - left) >> 1);
            if(arr[mid + k] - x < x - arr[mid]) left = mid + 1;
            else  right = mid;
        }
        vector<int> result(k);
        for(int i = 0; i < k; ++i) result[i] = arr[left + i];
        return result;
    }
};

// https://leetcode.com/problems/find-k-closest-elements/solutions/462664/python-binary-search-with-detailed-explanation/
class Solution2 {
public:
    // TC: O(log(N-k) + k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while(left < right){
            int mid = left + ((right - left) >> 1);
            if(x <= arr[mid])  right = mid;
            else if(x >= arr[mid + k]) left = mid + 1;
            else if(arr[mid + k] - x < x - arr[mid]) left = mid + 1;
            else  right = mid;
        }
        vector<int> result(k);
        for(int i = 0; i < k; ++i) result[i] = arr[left + i];
        return result;
    }
};

class Solution3 {
public:
    // TC: O(N)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        while(right - left + 1 > k){
            if(x - arr[left] > arr[right] - x) ++left;
            else --right;
        }
        vector<int> result(k);
        for(int i = 0; i < k; ++i) result[i] = arr[left++];
        return result;
    }
};

class Solution4 {
public:
    // TC: O(logN + k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1, arr_size = arr.size();
        int index_of_closest_to_x = -1;
        int min_diff = INT_MAX;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            int diff = abs(arr[mid] - x);
            if(diff <= min_diff) {
                if(diff < min_diff || -1 == index_of_closest_to_x || arr[mid] < arr[index_of_closest_to_x]) index_of_closest_to_x = mid;
                min_diff = diff;
            }
            if(x > arr[mid]) left = mid + 1;
            else if(x < arr[mid]) right = mid - 1;
            else break;
        }
        int l = index_of_closest_to_x, r = index_of_closest_to_x;
        for(int i = 1; i < k; ++i){
            if(0 == l) ++r;
            else if(r + 1 == arr_size) --l;
            else{
                int ldiff = abs(arr[l - 1] - x), rdiff = abs(arr[r + 1] - x);
                if(ldiff < rdiff) --l;
                else if(ldiff > rdiff) ++r;
                else if(arr[l - 1] < arr[r + 1]) --l;
                else ++r;
            }
        }
        vector<int> result(k);
        for(int i = 0; i < k; ++i) result[i] = arr[l++];
        return result;
    }
};

class Solution5 {
public:
    // TC: O(logN + k*logk)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1, arr_size = arr.size();
        int index_of_closest_to_x = -1;
        int min_diff = INT_MAX;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            int diff = abs(arr[mid] - x);
            if(diff <= min_diff) {
                if(diff < min_diff || -1 == index_of_closest_to_x || arr[mid] < arr[index_of_closest_to_x]) index_of_closest_to_x = mid;
                min_diff = diff;
            }
            if(x > arr[mid]) left = mid + 1;
            else if(x < arr[mid]) right = mid - 1;
            else break;
        }
        int l = index_of_closest_to_x - 1, r = index_of_closest_to_x + 1;
        vector<int> result{arr[index_of_closest_to_x]};
        while(--k > 0){
            int ldiff = l >= 0 ? abs(arr[l] - x) : INT_MAX, rdiff = r < arr_size ? abs(arr[r] - x) : INT_MAX;
            if(ldiff < rdiff) result.push_back(arr[l--]);
            else if(ldiff > rdiff) result.push_back(arr[r++]);
            else if(ldiff == rdiff){
                if(arr[l] < arr[r]) result.push_back(arr[l--]);
                else result.push_back(arr[r++]);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

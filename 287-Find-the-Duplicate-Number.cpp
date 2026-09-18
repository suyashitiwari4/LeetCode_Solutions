class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            
            // 1. Fully count first
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) count++;
            }
            
            // 2. Update boundaries AFTER the loop finishes
            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
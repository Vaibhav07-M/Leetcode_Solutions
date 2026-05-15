class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right) {
            
            int mid = left + (right - left) / 2;
            
            // minimum is in right half
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                // minimum is at mid or left half
                right = mid;
            }
        }
        
        return nums[left];
    }
};
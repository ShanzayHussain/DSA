class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Sort the array
        int closestSum = nums[0] + nums[1] + nums[2]; 
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;    
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }
                if (sum < target) {
                    left++; 
                } else if (sum > target) {
                    right--; 
                } else {
                    return sum; 
                }
            }
        }
        return closestSum;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1); 
        
        int left = 0, right = m, halfLen = (m + n + 1) / 2;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = halfLen - i;
            
            int maxLeft = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight = (i == m) ? INT_MAX : nums1[i];
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            if (maxLeft <= minRight2 && maxLeft2 <= minRight) {
                if ((m + n) % 2 == 0)
                    return (max(maxLeft, maxLeft2) + min(minRight, minRight2)) / 2.0;
                else
                    return max(maxLeft, maxLeft2);
            } else if (maxLeft > minRight2) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};
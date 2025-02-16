class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);  // Ensures binary search on smaller array
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;

        while (low <= high) {
            int m1 = (low + high) / 2;
            int m2 = left - m1;

            int l1 = (m1 > 0) ? nums1[m1 - 1] : INT_MIN;
            int r1 = (m1 < n1) ? nums1[m1] : INT_MAX;
            int l2 = (m2 > 0) ? nums2[m2 - 1] : INT_MIN;
            int r2 = (m2 < n2) ? nums2[m2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {  // Found correct partition
                if ((n1 + n2) % 2 == 0) 
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                return max(l1, l2);
            } 
            else if (l1 > r2) high = m1 - 1;
            else low = m1 + 1;
        }
        return 0;
    }
};



// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int total = n + m;
        
//         bool isEven = (total % 2 == 0);
//         int midIdx = total / 2;
        
//         int i = 0, j = 0, idx = -1;
//         int num1 = 0, num2 = 0;

//         while (idx < midIdx) {
//             int val;
//             if (i < n && (j >= m || nums1[i] <= nums2[j])) {
//                 val = nums1[i++];
//             } else {
//                 val = nums2[j++];
//             }

//             num1 = num2;  // Store previous number
//             num2 = val;   // Store current number
//             idx++;
//         }

//         return isEven ? (num1 + num2) / 2.0 : num2;
//     }
// };

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int total = n + m;
        
//         bool isEven = (total % 2 == 0);
//         int midIdx = total / 2;
        
//         int i = 0, j = 0, idx = -1;
//         int num1 = 0, num2 = 0;

//         while (idx < midIdx) {
//             int val;
//             if (i < n && (j >= m || nums1[i] <= nums2[j])) {
//                 val = nums1[i++];
//             } else {
//                 val = nums2[j++];
//             }

//             num1 = num2;  // Store previous number
//             num2 = val;   // Store current number
//             idx++;
//         }

//         return isEven ? (num1 + num2) / 2.0 : num2;
//     }
// };

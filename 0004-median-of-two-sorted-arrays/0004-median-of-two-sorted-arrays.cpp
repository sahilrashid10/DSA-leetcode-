class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);
            
        int n1 = nums1.size(), n2 = nums2.size();
        int size = n1 + n2;

        int low = 0, high = n1;
        while (low <= high) {

            int Px = low + (high - low) / 2;
            int Py = (n1 + n2 + 1) / 2 - Px;

            // left side
            int x1 = (Px != 0) ? nums1[Px - 1] : INT_MIN;
            int y1 = (Py != 0) ? nums2[Py - 1] : INT_MIN;

            // right side
            int x2 = (Px != n1) ? nums1[Px] : INT_MAX;
            int y2 = (Py != n2) ? nums2[Py] : INT_MAX;

            if (x1 <= y2 && y1 <= x2) {
                if (size % 2 == 0)
                    return (max(x1, y1) + min(x2, y2)) / 2.0;

                return max(x1, y1);
            }

            if (x1 <= y2) {
                low = Px + 1;
            } else
                high = Px - 1;
        }
        return -1;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// int n1 = nums1.size(), n2 = nums2.size();
//         int med = (n1 + n2)/2;
//         int k = 0;
//         int i=0, j=0;
//         int len1=-1, len2=-1;

//         while(i<n1 && j<n2){
//             if(nums1[i] <= nums2[j]){
//                 k++;

//                 if(k == med)
//                     len2 = nums1[i];

//                 if(k == med+1)
//                     len1 = nums1[i];
//                 i++;

//             }else{
//                 k++;

//                 if(k == med)
//                     len2 = nums2[j];

//                 if(k == med+1)
//                     len1 = nums2[j];

//                 j++;
//             }
//         }
//         while(i<n1){
//                 k++;

//                 if(k == med)
//                     len2 = nums1[i];

//                 if(k == med+1)
//                     len1 = nums1[i];
//                 i++;

//         }
//         while(j<n2){
//                 k++;

//                 if(k == med)
//                     len2 = nums2[j];

//                 if(k == med+1)
//                     len1 = nums2[j];

//                 j++;
//         }

//         int size = n1 + n2;
//         if(size % 2 == 0) return (len1 + len2)/ 2.0;
//         return len1;
//     }
// };
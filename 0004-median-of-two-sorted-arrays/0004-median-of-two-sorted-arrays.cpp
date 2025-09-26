class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); 
        int m = nums2.size(); 

        if(n > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int start = 0;
        int end = n;
        int N = n + m;
    //x - nums1, y = nums2, px elemets from nums1 on left, py ...;
        while(start <= end){
            //elements from x list on left
            int px = start + (end - start) / 2;
            //elements from y on left
            int py = (n + m + 1) / 2  - px;

        //left side
            int x1 = (px == 0) ? INT_MIN : nums1[px-1];
            int y1 = (py == 0) ? INT_MIN : nums2[py-1];

        //right side
            int x2 = (px == n) ? INT_MAX : nums1[px];
            int y2 = (py == m) ? INT_MAX : nums2[py];

            //sorted condition
            if(x1 <= y2 && y1 <= x2){
                if( N % 2 == 0){
                    return float(max(x1, y1) + (min(x2, y2)))/2;
                }else
                    return max(x1, y1);
            }
            if(x1 > y2)
                end = px - 1;
            else
                start = px + 1;
        }
        return -1;
    }
};
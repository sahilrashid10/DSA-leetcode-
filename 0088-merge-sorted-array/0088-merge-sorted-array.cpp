class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j = m+n-1;
        int k = n-1;

        if(n==0) return;
        if(m==0) {
            nums1 = nums2;
            return;
        }

        while(k >= 0 && i>=0){
            if(nums1[i] <= nums2[k]){
                nums1[j] = nums2[k];
                k--;
                j--;
            }else{
                nums1[j] = nums1[i];
                i--;
                j--;
            }
        }
        while(k >= 0){
            nums1[j] = nums2[k];
            j--;
            k--;
        }

    }
};
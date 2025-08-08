class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int med = (n1 + n2)/2;
        int k = 0;
        int i=0, j=0;
        int len1=-1, len2=-1;

        while(i<n1 && j<n2){
            if(nums1[i] <= nums2[j]){
                k++;
                
                if(k == med)
                    len2 = nums1[i];

                if(k == med+1)
                    len1 = nums1[i];
                i++;
                    
            }else{
                k++;
                
                if(k == med)
                    len2 = nums2[j];

                if(k == med+1)
                    len1 = nums2[j];
                    
                j++;        
            }
        }
        while(i<n1){
                k++;
                
                if(k == med)
                    len2 = nums1[i];

                if(k == med+1)
                    len1 = nums1[i];
                i++;   
                    
        }
        while(j<n2){
                k++;
                
                if(k == med)
                    len2 = nums2[j];

                if(k == med+1)
                    len1 = nums2[j];
                    
                j++;   
        }

        int size = n1 + n2;
        if(size % 2 == 0) return (len1 + len2)/ 2.0;
        return len1;
    }
};
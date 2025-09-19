class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[n-2] < nums[n-1]) return n-1;

        int s = 1, e = n-2;

        while(s <= e){
            int m = s + (e - s)/2;

            if(nums[m-1] < nums[m] && nums[m] > nums[m+1]){
                return m;
            }else if(nums[m-1] < nums[m]){
                s = m + 1;
            }else
                e = m-1;
        }
        return -1;
    }
};


// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return 0;

//         for(int i = 1; i < n-1; i++) {
//             if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
//                 return i;
//         }
//         return nums[0] > nums[n-1] ? 0:n-1;
//     }
// };
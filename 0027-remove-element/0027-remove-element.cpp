class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k=0;
        for(int i=0; i<n; i++){
            if(nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
};
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int count = 0;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             if(val == nums[i]){
//                 count++;
//                 nums[i] = 50;
//             }
//         }
//         sort(nums.begin(), nums.end());
//         return n - count;
//     }
// };
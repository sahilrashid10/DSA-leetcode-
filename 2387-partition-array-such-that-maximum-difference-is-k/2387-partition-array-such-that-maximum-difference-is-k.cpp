class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<int> arr(1e5+1);
        for(int i=0; i<nums.size(); i++){
            arr[nums[i]] = 1;
        }
        int count = 1;
        int min = -1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] != 0){
                if(min == -1){
                    min = i;
                    continue;
                }
                if(i - min > k){
                    min = i;
                    count++;
                }
            }
        }
        return count;
    }
};


// class Solution {
// public:
//     int partitionArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         int ans = 1;
//         int start = nums[0];
//         for(int i=1; i<n; i++){
//             if(nums[i] - start > k){
//                 ans++;
//                 start = nums[i];
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        int max_idx = -1, min_idx = -1, bad_num_idx = -1;
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == minK)
                min_idx = i;
            if(nums[i] == maxK)
                max_idx = i;
            if(nums[i] > maxK || nums[i] < minK)
                bad_num_idx = i;

            int smaller_idx = min(max_idx, min_idx);
            int temp = max(0, smaller_idx - bad_num_idx);

            ans = ans + temp;

        }
        return ans;
    }
};



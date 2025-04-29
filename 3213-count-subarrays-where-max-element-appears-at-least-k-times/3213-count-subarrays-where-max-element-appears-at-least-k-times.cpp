class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(),
                maxi = *max_element(nums.begin(), nums.end());
        int i = 0, count = 0;
        long long ans = 0;

        for(int j = 0; j<n; j++){
            if(nums[j] == maxi) count++;

            while(count >= k){
                ans += n - j;
                if(nums[i] == maxi) count--;
                i++;
            }
        }
        return ans;
    }
};
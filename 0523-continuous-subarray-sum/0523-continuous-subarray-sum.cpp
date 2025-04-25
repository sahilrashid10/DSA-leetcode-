class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            
            int mod = sum % k;
            // i - mp[mod].second + 1 length of subarray
            if(mp.find(mod) != mp.end()){
                if(i - mp[mod] > 1)
                    return true;
            }
            else
                mp[mod] = i;
        }
        return false;

    }
};
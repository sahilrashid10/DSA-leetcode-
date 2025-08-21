class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        using ll = long long;
        ll sum = 0;
        vector<ll>m(k, LLONG_MAX);
        m[0] = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum % k;

            sum = min(m[rem], sum);

            m[rem] = min(sum, m[rem]);
        }
        return sum;
    }
};
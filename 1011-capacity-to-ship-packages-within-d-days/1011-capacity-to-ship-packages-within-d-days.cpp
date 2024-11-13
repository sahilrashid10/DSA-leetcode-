class Solution {
public:
    bool canShip(vector<int>& nums,int days,int m){
        int actual_days=0;
        int sum_weights=0;
        for(auto &it: nums){
            if(sum_weights+it > m){
                actual_days += 1;
                sum_weights = it;
            }
            else sum_weights += it;
            if(actual_days > days)
                return false;
        }
        actual_days += 1;
        return actual_days<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        while(s<=e){
            int m = s + (e - s)/2;
            if(canShip(nums, days, m))
                e = m-1;
            else s = m+1;
        }
        return s;
    }
};
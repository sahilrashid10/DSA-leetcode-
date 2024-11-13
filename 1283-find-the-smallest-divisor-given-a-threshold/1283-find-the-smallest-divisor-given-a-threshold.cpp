class Solution {
public:
    bool canDivide(vector<int>& nums,int t,int m){
        int sum = 0;
        for(auto &it:nums){
            sum += it/m;
            if(it % m != 0)
                sum += 1;
            if(sum > t)
                return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int s = 1;
        int e = *max_element(begin(nums), end(nums));
        while(s<=e){
            int m = s + (e-s)/2;
            if(canDivide(nums, t, m)){
                e = m-1;
            }
            else s = m+1;
        }
        return s;
    }
};
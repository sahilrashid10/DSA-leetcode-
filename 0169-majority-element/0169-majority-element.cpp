class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int &num:nums){
            m[num]++;
        }
        int ans;
        int maxFreq = 0;
        for(auto &[num, freq]:m){
            if(freq >= maxFreq){
                ans = num;
                maxFreq = freq;
            }
        }
        return ans;
    }
};
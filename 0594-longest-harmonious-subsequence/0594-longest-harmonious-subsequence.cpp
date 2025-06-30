class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int &num:nums)
            freq[num]++;
        
        int maxLen = 0;
        for(auto &[num, f]:freq){
            if(freq.count(num+1)){
                maxLen = max(maxLen, f + freq[num + 1]);
            }
        }
        return maxLen;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        unordered_map<int, int>lastSeen;
        for(int i=0; i<nums.size(); i++){
            int req = k-nums[i];
            if(lastSeen.find(req) != lastSeen.end()){
                return{lastSeen[req], i};
            }
            lastSeen[nums[i]] = i;
        }
        return {0, 0};
    }
};
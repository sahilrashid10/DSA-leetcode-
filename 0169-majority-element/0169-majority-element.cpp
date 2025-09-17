class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0], freq = 1;

        for(int i=1; i<nums.size(); i++){

            if(nums[i] == num) freq++;
            else{
                freq--;
                if(freq == 0){
                    num = nums[i];
                    freq = 1;
                }
            }

        }
        return num;
    }
};


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> m;
//         for(int &num:nums){
//             m[num]++;
//         }
//         int ans;
//         int maxFreq = 0;
//         for(auto &[num, freq]:m){
//             if(freq >= maxFreq){
//                 ans = num;
//                 maxFreq = freq;
//             }
//         }
//         return ans;
//     }
// };
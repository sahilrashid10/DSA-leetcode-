class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto &num:nums){
            count += (((int)log10(num) + 1)&1)^1;
        }
        return count;
    }
};





//O(n*d) time, O(d) space, d for to_string
// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int ans = 0;
//         for(int num:nums){
//             string s = to_string(num);
//             if(s.size() % 2 == 0)
//                 ans++;
//         }
//         return ans;
//     }
// };

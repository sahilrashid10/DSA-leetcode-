#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        long long ans = 0, cnt = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;  

        for (int x : nums) {
            if (x % m == k) 
                ++cnt;

            int mod = cnt % m;

            int need = (mod - k + m) % m;
            ans += freq[need];

            ++freq[mod];
        }

        return ans;
    }
};



// class Solution {
// public:
//     long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
//         int n = nums.size();
//         int ans = 0;

//         for(int i=0; i<n; i++){
//             int cnt = 0;
//             for(int j = i; j<n; j++){
//                 if(nums[j] % m == k)
//                     cnt++;
//                 if(cnt % m == k)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };
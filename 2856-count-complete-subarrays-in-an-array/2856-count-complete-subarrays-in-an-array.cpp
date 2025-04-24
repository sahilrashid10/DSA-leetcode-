class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int un = s.size();
        unordered_map<int, int> m;

        int ans = 0;
        int left = 0, right = 0;
        while(right < n){
            m[nums[right]]++;

            while(m.size() == un){
                ans += n - right;
                m[nums[left]]--;
                if(m[nums[left]] == 0)
                    m.erase(nums[left]);
                left++; 
            }
                
            right++;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         unordered_set<int> s(nums.begin(), nums.end());
//         int unique = s.size();
//         int ans = 0;
//         for(int i=0; i<n; i++){
//             unordered_set<int> s;
//             for(int j=i; j<n; j++){
//                 s.insert(nums[j]);
//                 if(s.size() == unique)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };
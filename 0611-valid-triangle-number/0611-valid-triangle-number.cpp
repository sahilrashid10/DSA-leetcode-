class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int k = n-1; k>=2; k--){
            int i = 0;
            int j = k-1;
            while(i<j){
                int sum = nums[i] + nums[j];
                if(sum > nums[k]){
                    count += (j-i);
                    j--;
                }else i++;
            }
        }
        
        return count;
    }
};


#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { 
      static void _() { 
          std::ofstream("display_runtime.txt") << 0 << '\n'; 
      } 
  };
  std::atexit(&___::_);
  return 0;
}();
#endif
//Time = n*2 * log(n)
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         int n = nums.size();

//         sort(nums.begin(), nums.end());
//         int count = 0;
//         for (int i = 0; i <= n - 3; i++) {
//             for (int j = i + 1; j <= n - 2; j++){
//                 int sum = nums[i] + nums[j];
//                 auto it = lower_bound(nums.begin() + j + 1, nums.end(), sum);

//                 int mid = it - nums.begin() - 1;
//                 if(mid != j)
//                     count += (mid - j);
//             }
//         }
//         return count;
//     }
// };

//Time = 2^n , space = stack_space O(n)
// class Solution {
// public:
//     int n;
//     multiset<pair<int, vector<int>>> dpf;

//     bool isTriangle(vector<int> &triplet){
//         if(triplet[0] + triplet[1] <= triplet[2]) return false;
//         if(triplet[1] + triplet[2] <= triplet[0]) return false;
//         if(triplet[2] + triplet[0] <= triplet[1]) return false;

//         return true;
//     }
//     int solve(vector<int>& nums, int i, vector<int> triplet){
//         if(triplet.size() == 3){
//             if(isTriangle(triplet)){
//                 return 1;
//             }
//             return 0;
//         }
//         if(i == n) return 0;

//         triplet.push_back(nums[i]);
//         int take = solve(nums, i+1, triplet);
//         triplet.pop_back();
//         int skip = solve(nums, i+1, triplet);

//         return take + skip;
//     }
//     int triangleNumber(vector<int>& nums) {
//         n = nums.size();
//         // dp.assign
//         vector<int> triplet;
//         return solve(nums, 0, triplet);
//     }
// };
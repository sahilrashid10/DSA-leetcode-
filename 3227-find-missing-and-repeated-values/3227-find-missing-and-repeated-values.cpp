class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        using ll = long long;
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows*cols;
        ll c_n = 0;
        ll o_n = (n * (n+1)) / 2;
        ll c_n2 = 0;
        ll o_n2 = (1ll * n * (n+1 )* (2*n + 1)) / 6;
        for(int r=0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                int num = grid[r][c];
                int num_sq = num*num;

                c_n2 += num_sq;
                c_n += num;
            }
        }

        ll x_minus_y = c_n - o_n;
        ll x_plus_y = (c_n2 - o_n2) / x_minus_y;

        int repeating = (x_minus_y + x_plus_y)/2;
        int missing = repeating - x_minus_y;

        vector<int> ans = {repeating, missing};

        return ans;
    }
};

// n^2log(n)
// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int total = n * n;

//         // flatten grid into a vector
//         vector<int> nums;
//         long long actualSum = 0;
//         for (int r = 0; r < n; r++) {
//             for (int c = 0; c < n; c++) {
//                 nums.push_back(grid[r][c]);
//                 actualSum += grid[r][c];
//             }
//         }

//         // find repeated by sorting
//         sort(nums.begin(), nums.end());
//         int repeated = -1;
//         for (int r = 1; r < nums.size(); r++) {
//             if (nums[r] == nums[r-1]) {
//                 repeated = nums[r];
//                 break;
//             }
//         }

//         // missing using sum
//         long long expectedSum = 1LL * total * (total + 1) / 2;
//         int missing = expectedSum - (actualSum - repeated);

//         return {repeated, missing};
//     }
// };

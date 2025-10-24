

class Solution {
public:
    vector<vector<int>> result;
    int n;

    void getPermutations(vector<int> &nums, int i){
        if(i == n){
            result.push_back(nums);
            return;
        }

        unordered_set<int> s;
        for(int j = i; j<n; j++){
            if(s.count(nums[j]) > 0) continue;

            s.insert(nums[j]);
            swap(nums[j], nums[i]);

            getPermutations(nums, i+1);
            swap(nums[j], nums[i]);

        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        getPermutations(nums, 0);
        return result;
    }
};
// T(n) ≈ O(n × n! × log (n!)) ≈ O(n² × n! × log n)
// S(n)=O(n) (recursion)+O(n×n!) (output)=O(n×n!) + n*n

// class Solution {
// public:
//     vector<vector<int>> result;
//     map<vector<int>, int> m;
//     int n;

//     void getPermutations(vector<int> &nums, int i){
//         if(i == n){
//             if(m.count(nums) < 1) {
//                 result.push_back(nums);
//                 m[nums] = 1;
//             }
//             return;
//         }

//         for(int j = i; j<n; j++){
//             swap(nums[j], nums[i]);
//             getPermutations(nums, i+1);
//             swap(nums[j], nums[i]);

//         }
//         return;
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         n = nums.size();
//         sort(nums.begin(), nums.end());
//         getPermutations(nums, 0);
//         cout<<m[{2, 3}];
//         return result;
//     }
// };
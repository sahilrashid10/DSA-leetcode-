/* NOTE
1:Sorting subset on Each Call: Sorting subset every
time sum == target is inefficient and may interfere with expected output order.
Since the recursive calls aren't based on any sorted structure, this can cause
unexpected duplicates or ordering issues I.E:LINE 23
*/
// TIME LIMIT EXCEEDED T=(O(2^n ⋅ m ⋅ klogk))(REC, NO_EL TO BE SORTED, SORTING)
//  class Solution {
//  public:
//      vector<vector<int>>ans;
//      vector<int>subset;
//      int sum;

//     bool NoDuplicates(vector<vector<int>>ans, vector<int>subset){
//         sort(subset.begin(), subset.end());
//         for(int i=0; i<ans.size(); i++){
//             sort(ans[i].begin(), ans[i].end());
//             if(ans[i] == subset) return false;
//         }
//         return true;
//     }
//     void solve(vector<int>&candidates, int target, int i){
//         if(sum == target){
//             // sort(subset.begin(), subset.end());
//             if(NoDuplicates(ans, subset)) ans.push_back(subset);
//             return;
//         }
//         if(i >= candidates.size() || sum > target) return;

//         sum += candidates[i];
//         subset.push_back(candidates[i]);
//         solve(candidates, target, i+1);

//         sum -= candidates[i];
//         subset.pop_back();
//         solve(candidates, target, i+1);

//         return;
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
//     {
//         solve(candidates, target, 0);
//         return ans;
//     }
// };
class Solution {
public:
    void solve(vector<int> &c, int t, vector<vector<int>> &a, vector<int> &s, int sum, int start) {
        if (sum == t) {
            a.push_back(s);
            return;
        }
        for (int i = start; i < c.size(); i++) {
            if (i > start && c[i] == c[i - 1])  // skip duplicates
                continue;
            if (sum + c[i] > t)  // early stopping condition
                break;
            s.push_back(c[i]);
            solve(c, t, a, s, sum + c[i], i + 1);
            s.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, ans, subset, 0, 0);
        return ans;
    }
};

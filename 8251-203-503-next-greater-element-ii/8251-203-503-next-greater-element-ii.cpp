//BRUTE FORCE : T=O(N^2), S=O(N)
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         vector<int>ans;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             int x = -1;
//             for(int j=i+1; j<2*n; j++){
//                 if(nums[i]<nums[j%n]){
//                     x=nums[j%n];
//                     break;
//                 }
//             }
//             ans.push_back(x);
//         }
//         return ans;
//     }
// };
////BRUTE FORCE : T=O(4N), S=O(2N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int>ans(n);
        for(int i=2*n-1 ; i>=0; i--){
            while(!s.empty() && s.top()<=nums[i%n])
                s.pop();
            if(i<n){
                ans[i] = s.empty()?-1:s.top();
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};
//Optimal wrt space T=O(4N),S=O(1)
class Solution {
public:
    int findSubArrays(const vector<int>&nums,const int &goal){
        if(goal < 0)
            return 0;
        int left = 0;
        int sum = 0;
        int count = 0;
        for(int right=0; right<nums.size(); right++){
            sum += nums[right];
            while(sum>goal){
                sum -= nums[left];
                left++;
            }
            count += right-left+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int LessEqualGoal = findSubArrays(nums, goal); // subarrays <= goal
        int LessGoal = findSubArrays(nums, goal-1); //subarrays < goal
        return LessEqualGoal - LessGoal;    //simple maths: X(<=) - X(<) = X(=)
    }
};
//OPTIMAL-1 T=O(N) S=O(N)
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         unordered_map<int, int>m;
//         m[0]=1;
//         int ans=0;
//         int sum = 0;
//         for(int i=0; i<n; i++){
//             sum += nums[i];
//             int rem = sum - goal;
//             if(m.find(rem) != m.end())
//                 ans += m[rem];
//             m[sum]++;
//         }
//         return ans;   
//     }
// };
//T=(4N), S=O(N)
class Solution {
public:
    int findSubArrays(const vector<int>&nums,const int &goal){
        if(goal < 0)
            return 0;
        int left = 0;
        int count = 0;
        int ans=0;
        for(int right=0; right<nums.size(); right++){
            if(nums[right]%2 != 0)
                count++;
            while(count>goal){
                if(nums[left]%2 != 0)
                    count--;
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
        int LessEqualGoal = findSubArrays(nums, goal); // subarrays <= goal
        int LessGoal = findSubArrays(nums, goal-1); //subarrays < goal
        return LessEqualGoal - LessGoal;    //simple maths: X(<=) - X(<) = X(=)
    }
};
//T,S =N
    // int n = nums.size();
    // unordered_map<int, int> m;
    // int oddCount = 0;
    // int ans = 0;
    // m[oddCount] = 1;  // To handle subarrays starting from the beginning
    // for (int i = 0; i < n; i++) {
    //     oddCount += nums[i]%2;
    //     if (m.find(oddCount-goal) != m.end()) {
    //         ans += m[oddCount-goal];
    //     }
    //     m[oddCount]++;
    // }
    // return ans;
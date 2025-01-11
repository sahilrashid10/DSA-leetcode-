class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(nums.size()==1 || k==1)
            return nums;

        deque<int>q;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(!q.empty()&& q.front() <= i-k)
                q.pop_front();

            while(!q.empty() && nums[q.back()]<=nums[i])
                q.pop_back();

            q.push_back(i);


            if(i>=k-1)
                ans.push_back(nums[q.front()]);
            
        }
    return ans;
    }
};
//BRUTE FORCE T=O(N*K) S=O(N);
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {

//         if(k==1 || nums.size()==1)
//          return nums;

//         vector<int>ans;
//         for(int i=0; i<=nums.size()-k; i++){
//             int maxi = nums[i];
//             for(int j=i+1; j<k+i; j++){
//                 maxi = max(nums[j], maxi);
//             }
//             ans.push_back(maxi);
//         }
//         return ans;
//     }
// };
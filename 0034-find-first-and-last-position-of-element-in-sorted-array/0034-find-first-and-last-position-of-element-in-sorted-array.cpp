class Solution {
public:
    vector<int>ans={-1,-1};
    int n;
    void searchFirst(vector<int>nums, int k, int s, int e){
        while(s<=e){
            int m = (s+e)/2;
            if(nums[m]==k){
                ans[0]=m;
                e = m-1;
            }
            else (nums[m]<k)?(s=m+1):(e=m-1);
        }
    }
    void searchSecond(vector<int>nums, int k, int s, int e){
        while(s<=e){
            int m = (s+e)/2;
            if(nums[m]==k){
                ans[1]=m;
                s = m+1;
            }
            else (nums[m]<k)?(s=m+1):(e=m-1);
        }
    }
    vector<int> searchRange(vector<int>& nums, int k) {
        n = nums.size();
        searchFirst(nums, k, 0, n-1);
        if(ans[0] == -1) return ans;    // saves logn time
        searchSecond(nums, k, 0, n-1);
        return ans;
    }
};
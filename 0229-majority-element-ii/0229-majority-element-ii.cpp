class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int n1=INT_MAX, n2=INT_MAX, c1=0, c2=0;
        for(int i=0; i<n; i++){
            if(c1 == 0 && nums[i] != n2){
                n1 = nums[i];
    
            }
            if(c2 == 0 && n1 != nums[i]){
                n2 = nums[i];
            }

            if(nums[i] == n1) c1++;
            else if(nums[i] == n2) c2++;
            else{
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1 = 0, c2 = 0;
        for(int i=0; i<n; i++){
            c1 += nums[i] == n1 ? 1:0; 
            c2 += nums[i] == n2 ? 1:0; 
        }
        if(c1 > n/3)
            ans.push_back(n1);
        if(c2 > n/3)
            ans.push_back(n2);
        return ans;

    }
};
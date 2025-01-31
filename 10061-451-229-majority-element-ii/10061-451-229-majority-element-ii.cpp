class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int f1=0, f2=0;
        int n1=INT_MIN, n2=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(f1==0 && nums[i]!=n2){
                n1=nums[i];
                f1=1;
            }else if(f2==0 && nums[i]!=n1){
                n2=nums[i];
                f2=1;
            }else if(nums[i] == n1)
                f1++;
            else if(nums[i] == n2)
                f2++;
            else{
                f1--;
                f2--;
            }
        }
        vector<int>ans;
        f1=0;
        f2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==n1)
                f1++;
            if(nums[i]==n2)
                f2++;
        }
        if(f1>nums.size()/3)
            ans.push_back(n1);
        if(f2>nums.size()/3)
            ans.push_back(n2);
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int, int>m;
//         for(int i=0; i<nums.size(); i++)
//             m[nums[i]]++;

//         vector<int> maxFreq;
//         for(auto &it:m){
//             if(it.second > nums.size()/3)
//             maxFreq.push_back(it.first);
//         }
//         return maxFreq;

//     }
// };
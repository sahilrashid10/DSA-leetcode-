class Solution {
public:
    void getNextGreaterMap(vector<int> &nums2, unordered_map<int, int>&nextGreater){
        stack<int>s;

        for(int i=nums2.size()-1; i>=0; i--){
            while(!s.empty() && nums2[i] > nums2[s.top()]){
                s.pop();
            }
            if(s.empty())
                nextGreater[nums2[i]] = -1;
            else 
                nextGreater[nums2[i]] = nums2[s.top()];
            s.push(i);
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        getNextGreaterMap(nums2, nextGreater);

        vector<int> ans(nums1.size());
        for(int i=0; i<ans.size(); i++){
            ans[i] = nextGreater[nums1[i]]; 
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>ans;
//         for(int &n1:nums1){
//             int count = -1;
//             for(int n2:nums2){
//                 if(n2 == n1){
//                     count = 0;
//                 }
//                 if(count != -1 && n2 > n1){
//                     count = n2;
//                     break;
//                 }  
//             }
//             if(count == 0)
//                 ans.push_back(-1);
//             else
//             ans.push_back(count);
//         }
//         return ans;
//     }
// };
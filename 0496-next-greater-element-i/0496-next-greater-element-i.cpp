class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> m;
        stack<int> s;

        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top() < nums2[i]){
                s.pop();
            }
            m[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int &num:nums1)
            ans.push_back(m[num]);
        
        return ans;
    }
};
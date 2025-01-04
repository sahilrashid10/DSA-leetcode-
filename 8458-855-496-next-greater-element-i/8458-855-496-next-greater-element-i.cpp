class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        int n, m;
        stack<int>s;
        n=nums2.size();
        m=nums1.size();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top()<nums2[i])
                s.pop();
            if(s.empty())
                mp[nums2[i]]=-1;
            else
                mp[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0; i<m; i++)
            ans.push_back(mp[nums1[i]]);
        return ans;
    }
};
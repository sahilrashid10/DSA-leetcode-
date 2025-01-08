class Solution {
    typedef long long ll;
    int n;
public:
    vector<int> findNGL(vector<int>& nums){
        vector<int>ans(n);
        stack<int>s;
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[s.top()]<=nums[i])
                s.pop();
            ans[i] = s.empty()?-1:s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> findNGR(vector<int>& nums){
        vector<int>ans(n);
        stack<int>s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && nums[s.top()]<nums[i])
                s.pop();
            ans[i] = s.empty()?n:s.top();
            s.push(i);
        }
        return ans;
    }
    ll GenerateMaxisSum(vector<int> &nums){
        vector<int>NGL = findNGL(nums);
        vector<int>NGR = findNGR(nums);
        stack<int>s;
        ll summ = 0;
        for(int i=0; i<n; i++){
            ll ngl =i-NGL[i];
            ll ngr =NGR[i]-i;
            summ += (1ll*nums[i]*ngl*ngr);
        }
        return summ;
    }
    vector<int> findNSL(vector<int>& nums){
        vector<int>ans(n);
        stack<int>s;
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[s.top()]>=nums[i])
                s.pop();
            ans[i] = s.empty()?-1:s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> findNSR(vector<int>& nums){
        vector<int>ans(n);
        stack<int>s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && nums[s.top()]>nums[i])
                s.pop();
            ans[i] = s.empty()?n:s.top();
            s.push(i);
        }
        return ans;
    }
    ll GenerateMinisSum(vector<int>& nums){
        vector<int>NSL = findNSL(nums);
        vector<int>NSR = findNSR(nums);
        stack<int>s;
        ll summ = 0;
        for(int i=0; i<n; i++){
            ll nsl =i-NSL[i];
            ll nsr =NSR[i]-i;
            summ += (1ll*nums[i]*nsl*nsr);
        }
        return summ;
    }
    long long subArrayRanges(vector<int>& nums) {
        n = nums.size();
        ll sumMaxis = GenerateMaxisSum(nums);
        ll sumMinis = GenerateMinisSum(nums);
        return sumMaxis - sumMinis;
    }
};
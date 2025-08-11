class Solution {
public:
    int n;
    void NSR(vector<int>& heights, vector<int>&v){
        stack<int> s;
         for(int i=n-1; i>=0; i--){
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            v[i] = !s.empty() ? s.top(): n;
            s.push(i);
        }
    }
    void NSL(vector<int>& heights, vector<int>&v){
        stack<int> s;
         for(int i=0; i<n; i++){
            while(!s.empty() && heights[i] <= heights[s.top()])
                s.pop();

            v[i] = !s.empty() ? s.top(): -1;
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        vector<int> nsLeft(n);
        nsLeft[0] = 0;
        vector<int> nsRight(n);

        NSL(heights, nsLeft);
        NSR(heights, nsRight);

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int left = nsLeft[i];
            int right = nsRight[i];

            int width = abs(right - left - 1);
            int area = width * heights[i];
            ans = max(ans, area); 
        }
        return ans;
    }
};
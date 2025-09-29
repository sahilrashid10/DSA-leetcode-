class Solution {
public:
    vector<int> leftMin;
    vector<int> rightMin;
    int n;

    void getLeftMin(vector<int>& h){
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && h[s.top()] >= h[i])
                s.pop();

            leftMin[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
    }
    void getRightMin(vector<int>& h){
        stack<int> s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && h[s.top()] >= h[i])
                s.pop();

            rightMin[i] = s.empty() ? n : s.top();
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        leftMin.resize(n);
        rightMin.resize(n);

        getLeftMin(heights);
        getRightMin(heights);

        int maxArea = 0;
        for(int i=0; i<n; i++){
            int width = rightMin[i] - leftMin[i] - 1;

            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};
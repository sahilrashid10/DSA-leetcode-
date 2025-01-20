class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0, l=0, r=cardPoints.size()-1, sum=0;
        for(l=0; l<k; l++)
            sum += cardPoints[l];
        ans = sum;
        for(l=k-1; l>=0; l--){
            sum -= cardPoints[l];
            sum += cardPoints[r];
            ans = max(ans, sum);
            r--;
        }
        return ans;
    }
};
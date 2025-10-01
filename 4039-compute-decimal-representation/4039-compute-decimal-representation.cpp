class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int i = 0;

        while(n > 0){
            long long temp = n%10;
            long long x = pow(10, i);
            temp = temp * x;
            if(temp != 0)
            ans.push_back(temp);
            n = n / 10;
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
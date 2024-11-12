class Solution {
public:

    bool canMake(vector<int> &bloomDay, int n, int m, int k){
        int actual_bou = 0;
        int count = 0;
        for(auto &it: bloomDay){
            if(m >= it) count += 1;
            else count = 0;
            if(count == k)
            {
                count = 0;
                actual_bou += 1;
            }
            if(actual_bou==n)
             return true;
        }
        return false;

    }
    int minDays(vector<int>& bloomDay, int n, int k) {
        if(bloomDay.size()/k < n) return -1;
        int s = 0;
        int e = *max_element(begin(bloomDay), end(bloomDay));
        while(s<=e){
            int m = s+(e-s)/2;
            if(canMake(bloomDay, n, m, k))
                e = m-1;
            else
                s = m+1;
        }
        return s;
    }
};
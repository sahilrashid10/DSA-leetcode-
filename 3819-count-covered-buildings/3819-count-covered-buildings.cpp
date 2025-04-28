class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        int m = b.size();
        vector<int> xl(n+1, n+1); // smallest x at each y
        vector<int> xr(n+1, 0);   // largest x at each y
        vector<int> yl(n+1, n+1); // smallest y at each x
        vector<int> yr(n+1, 0);   // largest y at each x

        for(auto &it : b){
            int x = it[0], y = it[1];
            xl[y] = min(xl[y], x);
            xr[y] = max(xr[y], x);
            yl[x] = min(yl[x], y);
            yr[x] = max(yr[x], y);
        }

        int count = 0;
        for(auto &it : b){
            int x = it[0], y = it[1];
            if(xl[y] < x && xr[y] > x && yl[x] < y && yr[x] > y) 
                count++;
        }
        return count;
    }
};

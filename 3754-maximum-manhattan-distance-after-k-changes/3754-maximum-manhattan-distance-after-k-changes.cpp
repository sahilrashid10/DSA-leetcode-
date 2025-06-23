class Solution {
public:
    int solve(string &s, int k, char d1, char d2){
        int dist = 0;
        int max_dist = 0;
        for(auto &c:s){
            if(c == d1 || c == d2) dist++;
            else if(k>0){
                k--;
                dist++;
            }else dist--;
            max_dist = max(max_dist, dist);
        }
        return max_dist;
    }
    int maxDistance(string s, int k) {
        int nw = solve(s, k, 'N', 'W');
        int ne = solve(s, k, 'E', 'N');
        int sw  = solve(s, k, 'S', 'W');
        int se  = solve(s, k, 'S','E');

        return max({nw,ne,sw, se});
    }
};
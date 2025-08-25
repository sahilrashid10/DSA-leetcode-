class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> freq;
        int m = grid.size();
        int n = m * m; 
        int RangeSum = (n * (n + 1)) / 2;
        int OriginalSum = 0;
        int rep;

        for(int i=0; i<m; i++){
            for(int j = 0; j<m; j++){
                int num = grid[i][j];
                if(freq.find(num) != freq.end())
                    rep = num;

                freq.insert(num);
                OriginalSum += num; 
            }
        }
        int diff = OriginalSum - RangeSum; 
        int mis = rep - diff;
        vector<int> v;
        v.push_back(rep); 
        v.push_back(mis);

        return v; 

    }
};
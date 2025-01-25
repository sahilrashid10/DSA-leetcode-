class Solution {
public:
    vector<int> generateRow(int row){
        vector<int>r;
        int res = 1;
        r.push_back(res);
        for(int col=1; col<row; col++){
            res = res*(row-col);
            res = res/col;
            r.push_back(res);
        }
        return r;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        for(int row=1; row<=numRows; row++){
            vector<int>temp = generateRow(row);
            result.push_back(temp);
        }
        return result;
    }
};
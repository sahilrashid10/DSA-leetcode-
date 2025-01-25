class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long res = 1; // Use long long to avoid overflow
        row.push_back(res);
        for (int col = 1; col <= rowIndex; col++) {
            res = res * (rowIndex - col + 1) / col; // Calculate the next value
            row.push_back(static_cast<int>(res));  // Cast back to int for the result
        }
        return row;
    }
};

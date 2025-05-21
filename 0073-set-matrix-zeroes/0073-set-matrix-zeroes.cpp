class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int row = m.size();
        int col = m[0].size();
        int k = 1;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(m[i][j] == 0){
                    if(j == 0)
                        k = 0;
                    else{
                        m[i][0] = 0;
                        m[0][j] = 0;
                    }
                }
            }
        }
        for(int i=row-1; i>0; i--){
            for(int j=col-1; j>0; j--){
                    if(m[i][0] == 0 || m[0][j] == 0)
                        m[i][j] = 0;
            }
        }
        for(int j = col-1; j>=0; j--){
            if(m[0][0] == 0)
                m[0][j] = 0;
        }

        for(int i = 0; i<row; i++){
            if(k == 0)
                m[i][0] = 0;
        }
    }
};
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& m) {
//         int row = m.size();
//         int col = m[0].size();

//         vector<int> ver(row, 1);
//         vector<int> hor(col, 1);

//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 if(m[i][j] == 0){
//                     ver[i] = 0;
//                     hor[j] = 0;
//                 }
//             }
//         }
//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 if(ver[i] == 0 || hor[j] == 0){
//                     m[i][j] = 0;
//                 }
//             }
//         }
//     }
// };
// class Solution {
// public:
//     void setZeros(vector<vector<int>>& m, int i, int j){
//         for(int k=0; k<m[0].size(); k++)
//             m[i][k] = 0;

//         for(int k=0; k<m.size(); k++)
//             m[k][j] = 0;
//     }
//     void setZeroes(vector<vector<int>>& m) {
//         int row = m.size();
//         int col = m[0].size();

//         vector<vector<int>> temp = m;

//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 if(m[i][j] == 0)
//                     setZeros(temp, i, j);
//             }
//         }
//         m = temp;
//     }
// };
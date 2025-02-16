class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int r = arr.size();
        int c = arr[0].size();
        int low = 0;
        // **************** imp 
        int high = (r * c) - 1;

        while(low <= high){
            int m = (low + high) / 2;
        // **************** imp 
            int curRow = m / c;
            int curCol = m % c;

            int curElement = arr[curRow][curCol];

            if(curElement == k) return true;

            else if(curElement < k) low = m + 1;

            else high = m - 1;
        }

        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& arr, int k) {
//         int r = arr.size();
//         int c = arr[0].size();
        
//         for(int i = 0; i < r; i++){
            
//             int curRow = 0;
            
//             int low = 0, high = c - 1;
//             while(low <= high){
                
//                 int mid = (low + high) / 2;

//                 if(arr[i][mid] == k)
//                     return true;

//                 else if(arr[i][mid] > k)
//                     high = mid - 1;
                    
//                 else low = mid + 1;
//             }
//         }
//         return false;
//     }
// };  

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDia = 0;
        int area = 0;

        for(auto &it:dimensions){
            int w = it[0], h = it[1];
            int dia = w*w + h*h;

            if(dia > maxDia || (dia == maxDia && w * h > area)){
                maxDia = dia;
                area = w * h;  
            }
        }
        return area;
    }
};
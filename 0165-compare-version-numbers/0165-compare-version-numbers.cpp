class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();

        int ans = 0;
        int i=0, j=0;
        while(i < n || j < m){
            long long n1 = 0;
            while(i < n && version1[i] != '.'){
                n1 = n1*10 + version1[i] - '0';
                i++;
            }
            long long n2 = 0;
            while(j < m && version2[j] != '.'){
                n2 = n2*10 + version2[j] - '0';
                j++;
            }

            if(n1 > n2) return 1;
            else if(n1 < n2) return -1;

            i++;
            j++;
        }
        return 0;
    }
};
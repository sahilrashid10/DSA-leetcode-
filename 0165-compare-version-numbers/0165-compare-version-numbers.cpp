class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = version1.size();
        int v2 = version2.size();

        int i1=0, i2=0;
        while(i1 < v1 && i2 < v2){
            string s1 = "", s2="";

            while(i1<v1 && version1[i1] != '.'){ 
                s1 += version1[i1];
                i1++;
            }
            while(i2<v2 && version2[i2] != '.'){ 
                s2 += version2[i2];
                i2++;
            }
            if(stoi(s1) < stoi(s2)) return -1;

            else if(stoi(s1) > stoi(s2)) return 1;

            i1++;
            i2++;
        }

        
        while(i1<v1){

            string s1 = "";
            while(i1<v1 && version1[i1] != '.'){ 
                s1 += version1[i1];
                i1++;
            }
            if(stoi(s1) < 0) return -1;

            else if(stoi(s1) > 0) return 1;

            i1++;
        }
        while(i2<v2){

            string s2 = "";
            while(i2<v2 && version2[i2] != '.'){ 
                s2 += version2[i2];
                i2++;
            }
            if(stoi(s2) > 0) return -1;

            else if(stoi(s2) < 0) return 1;

            i2++;
        }

        return 0;
    }
};
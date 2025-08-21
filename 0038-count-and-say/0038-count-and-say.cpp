class Solution {
public:
    string countAndSay(int n) {

        string s = "1";


        for(int j=2; j<=n; j++){

            int i=0, freq=0;
            char prev = s[0];
            string ans = "";
            while(i < s.size()){
                if(s[i] == prev){
                    freq++;
                    i++;
                }else{
                    ans += to_string(freq) + prev;
                    freq = 0;
                    prev = s[i];
                }
            }
            ans += to_string(freq) + prev;
            s = ans;
        } 
        return s;
    }
};


// class Solution {
// public:
//     string countAndSay(int n) {
//         if(n == 1) return "1";

//         string s = countAndSay(n-1);

//         string ans = "";
//         int i=0, freq=0;
//         char prev = s[0];
//         while(i < s.size()){
//             if(s[i] == prev){
//                 freq++;
//                 i++;
//             }else{
//                 ans += to_string(freq) + prev;
//                 freq = 0;
//                 prev = s[i];
//             }
//         } 
//         ans += to_string(freq) + prev;
//         return ans;
//     }
// };
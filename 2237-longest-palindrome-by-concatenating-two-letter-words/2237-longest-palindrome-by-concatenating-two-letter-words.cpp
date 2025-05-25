class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;

        int result = 0;
        for(auto &word:words){

            string req = word;
            swap(req[0], req[1]);

            if(m[req] > 0){
                result += 4;
                m[req]--;
            }else
                m[word]++;
        }

        for(auto &it:m){
            string s = it.first;
            if(s[0] == s[1] && it.second > 0){
                result += 2;
                break;
            }
        }
        return result;
    }
};
class Solution {
public:
    bool isAns(string& w1, unordered_map<char, int>& mp2){
        unordered_map<char, int>mp1;
        for(char &c:w1){
            mp1[c]++;
        }
        for(auto &it: mp2) {
            if(mp1[it.first] < it.second) 
                return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        unordered_map<char, int>mp2;
        vector<string>ans;
        for(string &word: w2){
            unordered_map<char, int>temp_freq;
            for(char &c: word){
                temp_freq[c]++;
            }
            for(auto &it:temp_freq){
                mp2[it.first] = max(mp2[it.first], it.second);
            }
        }
        for(string &word:w1){
            if(isAns(word, mp2))
                ans.push_back(word);
        }
    return ans;
    }
};
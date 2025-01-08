class Solution {
public:
    bool isPrefixAndSuffix(string &w1, string &w2){
        int i=0, j=0;

        while(i<w1.size()){
            if(w1[i]==w2[j]){
                i++;j++;
            }else
                return false;
        }
        i=w1.size()-1;
        j=w2.size()-1;
        while(i>=0){
            if(w1[i]==w2[j]){
                i--;j--;
            }else
                return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        if(words.size() == 1)
            return 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++ ){
            if(words[i].size()<=words[j].size()){
                if(isPrefixAndSuffix(words[i], words[j]))
                count++;
                }
            }
        }
        return count;
    }
};
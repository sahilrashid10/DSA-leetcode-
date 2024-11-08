class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i=0;
        int j=0;
        int n = sentence.size();
        char temp;
        if(sentence[0]!=sentence[n-1])return false;
        while(i<n-1){
            if(sentence[i+1]==' '){ 
                j=i;
                i+=2;
                if(sentence[i] != sentence[j])
                return false;
            }
            else i++;   
        }
        return true;
    }
};
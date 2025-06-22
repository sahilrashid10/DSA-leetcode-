class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int x = 0;
        string temp;
        for(int i=0; i<s.size(); i++){
            x++;
            temp += s[i];
            if(x == k){
                x = 0;
                result.push_back(temp);
                temp = "";
            }
        }
        if(x != 0){
            while(x != k){
                temp += fill;
                x++;
            }
            result.push_back(temp);
        }
        return result;
    }
};
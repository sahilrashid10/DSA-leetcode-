class Solution {
public:

    vector<string>ans;
    string temp;
    void solve(vector<string>&chz, int idx){
        if(idx >= chz.size()){
            ans.push_back(temp);
            return;
            }
        for(int i=0; i<chz[idx].size(); i++){
            temp += chz[idx][i];
            solve(chz, idx+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>chz;

        for(int i=0; i<digits.size(); i++){
            if(digits[i]=='2') chz.push_back("abc");
            if(digits[i]=='3') chz.push_back("def");
            if(digits[i]=='4') chz.push_back("ghi");
            if(digits[i]=='5') chz.push_back("jkl");
            if(digits[i]=='6') chz.push_back("mno");
            if(digits[i]=='7') chz.push_back("pqrs");
            if(digits[i]=='8') chz.push_back("tuv");
            if(digits[i]=='9') chz.push_back("wxyz");
        }
        solve(chz, 0);
        return ans;
    }
};
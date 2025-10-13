class Solution {
public:
    bool isPalindrome(string s) {

        // cout<<'A'- 0<<' '<<'Z'<<endl;
        // cout<<'a'- 0<<' '<<'z'<<endl;
        string temp = "";
        for(char &ch:s){
            if(('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')){
                char c = tolower(ch);
                temp += c;
            }else if(('0' <= ch && ch <= '9') )
                temp += ch;
        }
        cout<<temp;
        int i = 0;
        int j = temp.size()-1;
        while(i < j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
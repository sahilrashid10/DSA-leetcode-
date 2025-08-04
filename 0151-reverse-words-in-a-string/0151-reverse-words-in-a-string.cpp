class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i=0;

        while(i<s.size() && s[i] == ' ') i++;

        string temp = "";
        for(; i<s.size(); i++){
            while(i< s.size() && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(temp != "")
                st.push(temp);

            temp = "";
        }
        temp = "";
        while(!st.empty()){
            temp += st.top() + ' ';
            st.pop();
        }
        s = temp.substr(0,temp.size()-1);
        return s;
    }
};
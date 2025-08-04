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
            if(st.size() == 1)
                temp += st.top();
            else temp += st.top() + ' ';
            st.pop();
        }
        return temp;
    }
};
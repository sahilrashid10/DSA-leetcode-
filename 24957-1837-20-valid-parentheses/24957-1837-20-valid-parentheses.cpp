class Solution {
public:
    bool isValid(string st) {
        int n = st.size();
        stack<char>s;
        if(n%2 != 0 || n == 1)
            return false;
        for(auto &ch:st){
            if(s.empty()||ch=='[' || ch=='{'||ch=='(')
                s.push(ch);
            else{
                if(ch ==')' && s.top()=='(')
                    s.pop();
                else if(ch =='}' && s.top()=='{')
                    s.pop();
                else if(ch ==']' && s.top()=='[')
                    s.pop();
                else
                    return false;
        }
        }
        return s.empty();
    }
};
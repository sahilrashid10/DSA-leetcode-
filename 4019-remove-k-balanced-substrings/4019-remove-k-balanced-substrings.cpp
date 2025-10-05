class Solution {
public:
    string removeSubstring(string str, int k) {
        int n = str.size();

        stack<char> s;
        
        for(auto &c:str){
            s.push(c);

            if(s.size() >= 2*k){
                stack<char> temp;
                int x = k;
                while(!s.empty() && s.top() == ')' && x>0){
                    temp.push(s.top());
                    s.pop();
                    x--;
                }
                if(temp.size() == k){
                    int x = k;
                    while(!s.empty() && s.top() == '(' && x > 0){
                        temp.push(s.top());
                        s.pop();
                        x--;
                    }        
                }
                if(temp.size() != 2*k){
                    while(!temp.empty()){
                        s.push(temp.top());
                        temp.pop();
                    }
                }
            }
        }
        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int maxDiff(int num) {
        // return 8 incase of single digit number
        if(num / 10 == 0)  
            return 8;
        
        //For log(num) > 1
        string s = to_string(num);
        string x, y;
        x = y = s;

        char change_x = s[0];   // make's num greatest
        char change_y = s[0];   // makes num smallest
        // 2- cases if c_y is ' ' or (change_y is not ' ' and not '1')
        if(s[0] == '1'){
            int i=1;
            while(i<s.size() && (s[i] == '1' || s[i] == '0')){
                i++;
            }
            if(i < s.size())
                change_y = s[i];
        }
        if(s[0] == '9'){
            int i=1;
            while(i<s.size() && s[i] == '9'){
                i++;
            }
            if(i < s.size())
                change_x = s[i];
        }

        for(int i=0; i<s.size(); i++){
            if(s[i] == change_x){
                x[i] = '9';
            }
            if(s[i] == change_y && change_y != '1'){
                if(change_x == '1' && s[0] == '1')
                    y[i] = '0';
                else y[i] = '1';
            }
        }
        return stoi(x) - stoi(y);
    }
};
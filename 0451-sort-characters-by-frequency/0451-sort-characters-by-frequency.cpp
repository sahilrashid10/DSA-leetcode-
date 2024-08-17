class Solution {
public:
    typedef pair<char,int>P;
    string frequencySort(string s) {
        string ans="";
        vector<P> v(123);
        for(char& ch:s){
            int freq = v[ch].second;    //v[ascii_value_wali_pos]
            v[ch] = {ch, freq+1};
        }
        //using [&] for pass by refrence(bcz faster than normal)
        auto lambada = [&](P &p1, P &p2){
            return p1.second > p2.second;   //sice sorting in descending order
        };

        sort(v.begin(),v.end(),lambada);
        
        for(auto& it: v){
            int ch = it.first;
            int freq = it.second;
            string temp = string(freq,ch);
            ans += temp;

        }
        return ans;
    }
};
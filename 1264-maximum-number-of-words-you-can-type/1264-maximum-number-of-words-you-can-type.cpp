class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        text += ' ';        
        int count = 0;
        unordered_map<char, int> m;
        for(auto &c: brokenLetters)
            m[c] = 1;
        for(int i=0; i<text.size(); i++){
            char c = text[i];

            if(c == ' ') {
                count++;
                continue;
            }

            if(m.find(c) != m.end()){
                while(c != ' ' && i < text.size()){
                    c = text[++i];
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        set<string> s(bank.begin(), bank.end());
        if(s.count(endGene) == 0) return -1;

        vector<char> input = {'A', 'C', 'G', 'T'};
        queue<pair<int, string>> q;
        q.push({0, startGene});

        while(!q.empty()) {
            auto[n, gene] = q.front();
            q.pop();
            
            if(gene == endGene)
                return n;
            
            for(int i=0; i<gene.size(); i++) {
                string temp = gene;
                for(int j=0; j<input.size(); j++) {
                    if(input[j] == temp[i])  continue;

                    temp[i] = input[j];

                    if(s.count(temp) > 0) {
                        q.push({n+1, temp});
                        s.erase(temp);
                    }
                }
            }
        }
        return -1;
    }
};
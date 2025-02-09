class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int n) {

        map<int, int> freq;

        for (int& it : hand)

            freq[it]++;

        while (!freq.empty()) {

            auto it = freq.begin()->first;
            for (int i = 0; i < n; i++) {

                int nextCard = it+i;

                if (freq[nextCard] == 0)
                    return false;
                
                freq[nextCard]--;

                if(freq[nextCard] == 0)
                    freq.erase(nextCard);
            }
        }
        return true;
    }
};
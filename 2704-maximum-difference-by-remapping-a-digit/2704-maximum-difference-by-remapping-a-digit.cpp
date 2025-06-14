class Solution {
public:
    int minMaxDifference(int num) {
        string numb = to_string(num);
        string maxi = numb, mini = numb;

        char change_maxi = ' ';
        char change_mini = ' ';

        change_mini = numb[0];

        // Apply changes
        for (int i = 0; i < numb.size(); ++i) {
            if(numb[i] != '9' && change_maxi == ' ')
                change_maxi = numb[i];

            if (numb[i] == change_maxi)
                maxi[i] = '9';

            if (numb[i] == change_mini)
                mini[i] = '0';
        }

        return stoi(maxi) - stoi(mini);
    }
};

class Solution {
public:
    vector<int> asteroidCollision(const vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            bool alive = true;

            while (!st.empty() && a < 0 && st.back() > 0) {
                if (abs(a) > st.back()) {
                    st.pop_back(); // destroy top, continue checking
                } else if (abs(a) == st.back()) {
                    st.pop_back(); // both destroyed
                    alive = false;
                    break;
                } else {
                    alive = false; // current destroyed
                    break;
                }
            }

            if (alive) st.push_back(a);
        }

        return st;
    }
};

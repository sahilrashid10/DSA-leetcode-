class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        unordered_set<int> s;

        int i = 0, count = 0;
        while (i < nums.size()) {
            if (st.empty()) {
                st.push(nums[i]);
                s.insert(nums[i]);          
            } else {
                while (!st.empty() && st.top() > nums[i]) {
                    count++;
                    s.erase(st.top());      
                    st.pop();
                }
                if (s.find(nums[i]) == s.end()) {
                    st.push(nums[i]);
                    s.insert(nums[i]);
                }
            }
            i++;
        }

        while(!st.empty()){
            if(st.top() != 0)
                count++;
            st.pop();
        }
        return count;
    }
};

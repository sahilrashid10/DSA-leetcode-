class Solution {
public:
    void merge(vector<int>& ans, int s, int m, int e) {
        vector<int> left(ans.begin() + s, ans.begin() + m + 1);
        vector<int> right(ans.begin() + m + 1, ans.begin() + e + 1);

        int i=0, j=0;
        int k = s;
        while(i<left.size() && j < right.size()){
            if(left[i] <= right[j])
                ans[k++] = left[i++];
            else
                ans[k++] = right[j++];
        }
        while(i<left.size())
            ans[k++] = left[i++];

        while(j < right.size())
            ans[k++] = right[j++];
        
    }
    void mergeSort(vector<int>& ans, int s, int e) {
        if (s >= e)
            return;

        int m = s + (e - s) / 2;

        mergeSort(ans, s, m);
        mergeSort(ans, m + 1, e);
        merge(ans, s, m, e);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans = nums;
        mergeSort(ans, 0, nums.size() - 1);
        return ans;
    }
};
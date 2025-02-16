class Solution {
public:
    void countPairs(vector<int>& nums, int left, int mid, int right, int& count) {
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) j++;
            count += (j - (mid + 1));
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        for (int k = 0; k < temp.size(); k++)
            nums[left + k] = temp[k];
    }

    void mergeSort(vector<int>& nums, int left, int right, int& count) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        
        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid + 1, right, count);
        
        countPairs(nums, left, mid, right, count);
        merge(nums, left, mid, right);
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);
        return count;
    }
};

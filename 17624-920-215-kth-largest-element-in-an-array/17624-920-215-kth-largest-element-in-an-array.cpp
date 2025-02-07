class Solution {
public:
    int quickSelect(vector<int>& nums, int i, int j) {
        int pivot = nums[i];
        int p = i;
        i++;
        while (i <= j) {
            if (nums[i] < pivot && nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if ( i<=j && nums[i] >= pivot) i++;

            if (i<=j && nums[j] <= pivot) j--;
        }
        swap(nums[p], nums[j]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int i = 0, j = nums.size() - 1, p = 0;

        while (true) {

            p = quickSelect(nums, i, j);

            if (p == k - 1)
                break;

            else if (p < k - 1) i = p + 1;

            else j = p - 1;
        }
        return nums[p];
    }
};

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> p;

//         for(auto &it: nums){
//             p.push(it);
//             if(p.size()>k)
//                 p.pop();
//         }
//         return p.top();
//     }
// };
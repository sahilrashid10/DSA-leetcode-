class Solution {
public:
    int n;

    int getPivotIdx(vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int Pi = left;
          while(left < right){
            if(nums[left] > pivot){
                swap(nums[left], nums[Pi]);
                Pi++;
            }
            left++;
        }
        swap(nums[Pi], nums[right]);

        return Pi;
    }
    int findKthLargest(vector<int>& nums, int k) {
        n = nums.size();

        int left = 0, right = n-1;
        k--;
        while(true){
            int Pi = getPivotIdx(nums, left, right);
            if(Pi > k)
                right = Pi - 1;
            else if(Pi < k)
                left = Pi + 1;
            else return nums[Pi];
         }
        return 0;
    }
};


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         //min-heap
//         priority_queue<int, vector<int>, greater<int>> h;
//         int i=0;
//         while(i<nums.size()){
//             h.push(nums[i]);

//             if(h.size() > k) 
//                 h.pop();
            
//             i++;
//         }
//         return h.top();
//     }
// };
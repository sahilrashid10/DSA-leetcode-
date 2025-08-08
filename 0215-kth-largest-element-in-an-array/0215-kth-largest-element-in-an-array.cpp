class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min-heap
        priority_queue<int, vector<int>, greater<int>> h;
        int i=0;
        while(i<nums.size()){
            h.push(nums[i]);

            if(h.size() > k) 
                h.pop();
            
            i++;
        }
        return h.top();
    }
};
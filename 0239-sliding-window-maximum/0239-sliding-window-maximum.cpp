class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            // Remove elements from the front if they are out of the current window
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            // Remove all elements smaller than the current from the back
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Start recording the result once we have at least k elements
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }

        }
        return ans;
    }
};
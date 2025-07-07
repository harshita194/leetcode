class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxlength =0;
        for(int num : nums){
            if (numSet.count(num - 1) == 0) {
                int currentStreak = 1;
                while (numSet.count(num + currentStreak)) {
                    currentStreak++;
                }

                maxlength = max(maxlength, currentStreak);
            }
        }
        return maxlength;
    }
};
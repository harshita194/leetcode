class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        // step 1 : store element in unordered set
        unordered_set<int> numSet(nums.begin() , nums.end());
        
        // step 2 : iterate through each number & check if number is start of a sequence 
        int maxLength = 0;

        for(int num : numSet){
            if (numSet.count(num - 1) == 0) {
                int currentStreak = 1;
                while (numSet.count(num + currentStreak)) {
                    currentStreak++;
                }

                maxLength = max(maxLength, currentStreak);
            }
        }
        return maxLength;
    }
};
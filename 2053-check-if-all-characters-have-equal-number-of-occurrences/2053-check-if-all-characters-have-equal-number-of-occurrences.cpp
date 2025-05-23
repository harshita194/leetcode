class Solution {
public:
    bool areOccurrencesEqual(string s) {
         vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int target = 0;
        for (int count : freq) {
            if (count > 0) {
                if (target == 0)
                    target = count;
                else if (count != target)
                    return false;
            }
        }

        return true;
    }
};
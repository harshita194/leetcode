class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long maxi1 = LLONG_MIN;
        long long maxi2 = LLONG_MIN;
        long long maxi3 = LLONG_MIN;

        for (int num : nums) {
            if (num == maxi1 || num == maxi2 || num == maxi3) continue;

            if (num > maxi1) {
                maxi3 = maxi2;
                maxi2 = maxi1;
                maxi1 = num;
            } else if (num > maxi2) {
                maxi3 = maxi2;
                maxi2 = num;
            } else if (num > maxi3) {
                maxi3 = num;
            }
        }

        return (maxi3 == LLONG_MIN) ? maxi1 : maxi3;
    }
};

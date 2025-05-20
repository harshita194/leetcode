class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = abs((long long) dividend);
        long long dvs = abs((long long) divisor);
        long long quotient = 0;
        for(int i=31; i>=0; i--){
            if((dvs << i) <= dvd){
                dvd -= (dvs << i);
                quotient |= (1LL << i);
            }
        }
        return sign * quotient;
    }
};
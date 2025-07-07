class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxlen = 0;
        for(int num : nums){
            freq[num]++;
        }
        for(auto& [key,value] : freq){
            if(freq.count(key+1)){
                maxlen = max(maxlen, value + freq[key+1]);
            }
        }
        return maxlen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> lastseen;
        int maxlen = 0;
        int start = 0;
        for(int end =0; end<s.size(); end++){
            char current = s[end];
            if(lastseen.find(current) != lastseen.end() && lastseen[current] >= start){
                start = lastseen[current] + 1;
            }
            lastseen[current] = end;
            maxlen = max(maxlen, end-start+1);
        }
        return maxlen;
    }
};
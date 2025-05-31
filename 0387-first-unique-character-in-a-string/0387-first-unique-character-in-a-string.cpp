class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<char,int> count;
        // for(char ch : s){
        //     count[ch]++;
        // }

        // for(int i=0; i<s.length(); i++){
        //     if(count[s[i]] == 1){
        //         return i;
        //     }
        // }
        // return -1;


        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};
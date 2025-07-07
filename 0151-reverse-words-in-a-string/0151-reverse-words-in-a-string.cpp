class Solution {
public:
    string reverseWords(string s) {
        string result, temp;
        stringstream ss(s);
        while(ss >> temp){
            result = temp + " " + result;
        }
        result.pop_back();
        return result;
    }
};
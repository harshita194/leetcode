class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        unordered_map<int,int> mp;
        sort(sortedArr.begin(),sortedArr.end());
        int rank = 1;
        for(int num : sortedArr){
            if(mp.find(num) == mp.end()){
                mp[num] = rank++;
            }
        }
        vector<int> result;
        for(int num : arr){
            result.push_back(mp[num]);
        }
        return result;
    }
};
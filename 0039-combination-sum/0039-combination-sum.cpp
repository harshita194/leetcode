class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            // Found a valid combination
            result.push_back(path);
            return;
        }

        if (target < 0 || index == candidates.size()) {
            // No valid combination from here
            return;
        }

        // Choice 1: Pick the current number
        if (candidates[index] <= target) {
            path.push_back(candidates[index]);
            solve(index, candidates, target - candidates[index], path, result);
            path.pop_back(); // Backtrack
        }

        // Choice 2: Skip the current number
        solve(index + 1, candidates, target, path, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        solve(0, candidates, target, path, result);
        return result;
    }
};
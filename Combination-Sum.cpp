class Solution {
public:
    vector<vector<int>> sol;

    void solve(vector<int>& candidates, int start, int k, vector<int> now) {
        if (k == 0) {  
            sol.push_back(now);
            return;
        }
        if (start >= candidates.size() || k < 0) return;  

        
        now.push_back(candidates[start]);
        solve(candidates, start, k - candidates[start], now);  

        
        now.pop_back();
        solve(candidates, start + 1, k, now);  
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> now;
        solve(candidates, 0, target, now);  
        return sol;
    }
};

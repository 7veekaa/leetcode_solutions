class Solution {

    private:
    void solve(vector<int>& candidates, int target, vector<int> now, int start, vector<vector<int>>& sol) {  
        if(target < 0){
            return;
        }
        if(target == 0){
            sol.push_back(now);
            return;
        }
        for(int i = start; i < candidates.size(); i++){  
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            now.push_back(candidates[i]);
            solve(candidates, target - candidates[i], now, i + 1, sol);  
            now.pop_back();  
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> now;
        int n = candidates.size();  
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, now, 0, sol);

        return sol; 
    }
};

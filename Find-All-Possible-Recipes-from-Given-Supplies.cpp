class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> hehe(begin(supplies), end(supplies));
        
        int n=recipes.size(); 
        unordered_map<string, vector<int>> dependency;
        vector<int> indegree(n,0);
        
        for (int i=0; i<n;i++) {
            for (string& ing:ingredients[i]) {  
            if(!hehe.count(ing)) {
                dependency[ing].push_back(i);
                indegree[i]++;
                }
            }
        }

                    queue<int>mid;  
                     for (int i=0;i<n;i++) {
                    if (indegree[i]==0) {
                    mid.push(i);
            }
        }

        vector<string> sol;
        while (!mid.empty()) {
            int i=mid.front();
            mid.pop();
            string recipe=recipes[i];
            sol.push_back(recipe);

        for (int &idx:dependency[recipe]) {
             indegree[idx]--;
        if (indegree[idx]==0) {
         mid.push(idx);
                }
            }
        }
                return sol;
    }
};

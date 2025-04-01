class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> agmap;
        
        for(string& word:strs) {
            vector<int>freq(26,0);  
            for(char c:word) {
                freq[c-'a']++; 
            }

            string unique;
            for(int i=0;i<26;i++) {
                unique+=to_string(freq[i])+ '#'; 
            }
            agmap[unique].push_back(word);
        }

       
        
        vector<vector<string>>sol;
        for(auto& entry:agmap) {
        sol.push_back(entry.second); 
        }return sol;
    }
};

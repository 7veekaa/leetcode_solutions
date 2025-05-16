class Solution {
    bool isPalindrome(string& s, int le, int ri){
        while(le<ri){
            if(s[le]!=s[ri]) return false;
            le=le+1;
            ri=ri-1;
        }
        return true;
    }
    void explore(string& s, int index, vector<string>& recent, vector<vector<string>>& sol){
        int n=s.length();
        if(index==n){
            sol.push_back(recent);
            return;
        }
        for(int i=index;i<n;i++){
           if(isPalindrome(s, index, i)){
            recent.push_back(s.substr(index, i-index+1));
            explore(s, i+1, recent, sol);
        recent.pop_back();
            
           } 
        }
        
            }

    
    
public:
    vector<vector<string>> partition(string s) {
        
        vector<string>recent;
        vector<vector<string>>sol;
        explore(s, 0, recent, sol );
        return sol;
        
    }
};
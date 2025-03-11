class Solution {
    
public:
    int numberOfSubstrings(string s) {
        int le=0;
        int ri=0;
        int sol=0;
        int n=s.length();

        unordered_map<char, int> checkpoint;
        
        while(ri<n){  
         checkpoint[s[ri]]++;  
            
            
 while(checkpoint['a']>0 && checkpoint['b']>0 && checkpoint['c']>0){
                sol += (n-ri);  
                checkpoint[s[le]]--; 
                le++;
            } ri++;
        }
        
        
        
        
        return sol;
    }
};


//make spazeeeee in hash maps 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     int le=0;
     int ri=0;
        
        unordered_map<char, int> checkpoint;  
        unordered_map<char, int> target;      
        
        
        for (char ch:s1) {
            target[ch]++;
        }
        
     int n = s1.size();
    int m = s2.size();
        
        while (ri < m) {
            checkpoint[s2[ri]]++; 
            
            
         if ((ri-le+1)==n) {
                
         if (checkpoint==target) {
              return true;
                }

                 checkpoint[s2[le]]--;
         if (checkpoint[s2[le]]==0) {
     checkpoint.erase(s2[le]);  
                }le++; 
            }
            ri++; 
        }
        
        return false;
    }
};

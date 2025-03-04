class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
     int le = 0;
     int  ri = 0;
      int  lls = 0, utmost_freq = 0;
     int hash[26] = {0}; 

 while (ri < n) {
         hash[s[ri] - 'A']++;
            utmost_freq = max(utmost_freq, hash[s[ri] - 'A']); 

 while ((ri - le + 1) - utmost_freq > k) {
         hash[s[le] - 'A']--;
               le++;
            }

           
           
           
            lls = max(lls, ri - le + 1);
            ri++;
        }

        return lls;
    }

};

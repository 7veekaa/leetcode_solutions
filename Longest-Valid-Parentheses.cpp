#include <climits>

class Solution {

    //longest means sliding window
    //valid parenthesis reminds me of stack 
    /*logic: vector me ( aaye to push back krdo
    ) aaye toh bhi push, sol increment krdo
    window aage badhate jao */
    
public:
    int longestValidParentheses(string s) {
        int le=0, ri=0;
        int n=s.length();
        int sol=0;

        
        for(char c:s) {
            if(c=='(') {
                le++;
            }else{
                ri++;
            }
            if(ri==le) {
                sol = max(sol, 2*ri);
            }else if(ri>le) {
                le=ri=0;
            }
        }

        le=ri=0;

        
        for (int i=n-1;i>=0;i--) {
            if(s[i]==')') ri++;
            else le++;

            if (le==ri) {
                sol=max(sol, 2 * le);
            }else if(le>ri) {
                le=ri=0;
            }
        }

        return sol;
    }
};

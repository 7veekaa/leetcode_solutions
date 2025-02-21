#include <limits.h>

//initialise ans, traverse through x 
//extract digit
//update x
//check overflow with entire reversed and int max and int min and also if last digit exceeds the extracted digit
//update final reversed int and return

class Solution {
public:
    int reverse(int x) {
        int sol_rev = 0;
        
        while (x) {
            int digit = x % 10;  
            x /= 10;  
            
            
            if (sol_rev > INT_MAX / 10 || (sol_rev == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return 0;
            }
            if (sol_rev < INT_MIN / 10 || (sol_rev == INT_MIN / 10 && digit < INT_MIN % 10)) {
                return 0;
            }

            sol_rev = (sol_rev * 10) + digit; 
        }

        return sol_rev;
    }
};

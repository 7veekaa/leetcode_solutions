#include <vector>
using namespace std;

class Solution {
    // **drumrolllllssssss**
    // This is a sliding window question
    // Since we only need to return a numeric value and not the subarrays, better and optimal approaches can work
    // Better would include expanding and shrinking the 2 pointers to satisfy the condition, sum==odd where odd is initialized as odd==sum%10==1 somehow
    //x-y approach , hence count for odd and even , even already 1 for an empty subarray gives sum 0 

    const int MOD = 1e9 + 7;  

public:
    int numOfSubarrays(vector<int>& arr) {
    int sol = 0;  
    int le = 0;
    int ri = 0;
    int sum = 0;
        
 int odd = 0, even = 1;  
        
        for (int ri = 0; ri < arr.size(); ri++) {  
         sum += arr[ri];  
            
        if (sum % 2 == 0) {  
             sol = (sol + odd) % MOD;  
             even++;
     } else {  
     sol = (sol + even) % MOD;  
     odd++;
            }
        }
        
    return sol;
    }
};

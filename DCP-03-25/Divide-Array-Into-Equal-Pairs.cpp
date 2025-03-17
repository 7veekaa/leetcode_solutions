#include <vector>
#include <algorithm>

class Solution {
public:
    bool divideArray(std::vector<int>& nums) {
        int n = nums.size();
             if(n%2!=0) { 
    return false;
        }
        sort(nums.begin(),nums.end());

        for (int i=0; i<n;i+=2) {  
            if ((nums[i] ^ nums[i + 1])!=0) {
                return false;
            }
        }
return true;  
    }
};

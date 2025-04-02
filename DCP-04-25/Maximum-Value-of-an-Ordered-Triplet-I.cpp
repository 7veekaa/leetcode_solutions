class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
      
        long long sol=0;
        long long maxA=0;
        long long max_i=0;

        for(int i=0;i<nums.size();i++){
            sol=max(sol, maxA*nums[i]);
            maxA=max(maxA, max_i-nums[i]);
            max_i=max(max_i, (long long)nums[i]);


            
        }
        return sol;
        
    }
};
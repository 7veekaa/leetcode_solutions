class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int le=0;
        int ri=0;
        int ormask=0;
        int sol=0;
        int n=nums.size();
        while(ri<n){
            while((ormask & nums[ri]) != 0){
             ormask^=nums[le];
             le=le+1;
            }
            ormask|=nums[ri];
            sol=max(sol,ri-le+1);
            ri=ri+1;
        }
        return sol;
    }
};

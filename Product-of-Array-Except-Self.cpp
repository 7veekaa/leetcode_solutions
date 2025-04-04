class Solution {
    //treating sol as le_pre
    //jaha se ulta loop chalega, ri_prek as a vecotr ko eliminate krke int ki tarah use krlo
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>sol(n);
        sol[0]=1; 
        for(int i=1;i<n;i++){
            sol[i]=nums[i-1]*sol[i-1];
        }
         
        int right_prod=1;
        for(int i=n-1;i>=0;i--){
            sol[i]=sol[i]*right_prod;
            right_prod=right_prod*nums[i];
        }
        return sol;


        
    }
};
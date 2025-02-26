class Solution {

    //kadane's, O(n)


public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        

        int currmax=nums[0];
        int currmin=nums[0];
        int possum=nums[0];
        int negsum=nums[0];
        for(int i=1;i<n;i++){
            currmax=max(nums[i], currmax+nums[i]);
            possum=max(possum,currmax);
            currmin=min(nums[i],currmin+nums[i]);
            negsum=min(negsum,currmin);
          
        }
         return max(possum, abs(negsum));

         

        
        
        
    }
};
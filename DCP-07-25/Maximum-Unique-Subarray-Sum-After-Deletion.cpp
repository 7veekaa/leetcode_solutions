class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> cp;
        int sol=0;
        int neg=INT_MIN;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]<=0){
                neg=max(neg, nums[i]);
            }else if(!cp.count(nums[i])){
                sol+=nums[i];
                cp.insert(nums[i]);
            }
        }return sol==0 ? neg:sol;

        
    }
};
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int>cp;
        cp.push_back(nums[0]);
        int n=nums.size();        
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                cp.push_back(nums[i]);
            }
        }int sol=0;
        for(int i=1;i<cp.size()-1;i++){
            if((cp[i] > cp[i - 1] && cp[i] >cp[i + 1])|| 
                (cp[i] < cp[i - 1] && cp[i] < cp[i + 1])) {
                sol+=1;
            }
        }return sol;
    }
};

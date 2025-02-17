class Solution {
//sameeeeee question as single number III except answer me bas 1 hi val chahie
public:
    int singleNumber(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int XOR = nums[0];
        
    
        for(int i = 1; i < n; i++) {
            XOR = XOR ^ nums[i];
        }

        
        int right_most = XOR & ~(XOR - 1);
        
        int x = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] & right_most) {
                x = x ^ nums[i];  
            }
        }
        
        
        ans.push_back(x);
        return ans[0];  
    }
};

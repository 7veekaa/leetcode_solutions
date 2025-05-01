class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return{};
        }
        deque<int>checkpoint;
        vector<int>sol;
        for(int i=0;i<n;i++){
            while(!checkpoint.empty()&&checkpoint.front()<=i-k){
                checkpoint.pop_front();
            }
            while(!checkpoint.empty()&&nums[i]>=nums[checkpoint.back()]){
                checkpoint.pop_back();
            }
            checkpoint.push_back(i);
            if(i>=k-1) {
                sol.push_back(nums[checkpoint.front()]);
            }
        }
        return sol;
    }
};
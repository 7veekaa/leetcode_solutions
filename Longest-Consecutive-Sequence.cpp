class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;

        sort(nums.begin(),nums.end());

        int sol=1;
        int now=1;
        int last=nums[0];
        for (int i=1;i<nums.size();i++) {
            if (nums[i]==last+1) {
                now++;
                last= nums[i];
            }
            else if(nums[i]!=last) {
                now=1;
                last=nums[i];
            }sol=max(sol,now);
        }

        return sol;
    }
};

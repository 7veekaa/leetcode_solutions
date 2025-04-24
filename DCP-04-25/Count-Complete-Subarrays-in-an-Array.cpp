class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) { 
        int n=nums.size();
        unordered_set<int>unique(nums.begin(),nums.end());
        int allunique=unique.size();
        int sol=0;

        
        for (int i=0;i<n;++i) {
            unordered_map<int, int>freq;
            int newbie=0;
            for(int j=i;j<n;++j) {
                if(++freq[nums[j]]==1) {
                    newbie++;
                }if(newbie==allunique) {
                    sol++;
                }
            }
        }

        return sol;
    }
};

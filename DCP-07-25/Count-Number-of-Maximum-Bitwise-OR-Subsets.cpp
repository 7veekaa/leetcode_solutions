class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int XOR=0;
        for(int i=0;i<n;i++){
            XOR|=nums[i];
        }return subsets(0,0, nums, XOR);
    }

    int subsets(int index,int current_or,vector<int>& nums,int XOR){
        if(index==nums.size()){
            return current_or==XOR ? 1 : 0;
        }
        int takes=subsets(index+1,current_or|nums[index],nums,XOR);
        int skips=subsets(index+1,current_or,nums,XOR);
        return takes+skips;
    }
};

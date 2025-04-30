class Solution {
public:
    int trap(vector<int>& height) {
        int le=0,ri=height.size()-1;
        int sol=0;
        int h=0;
        int max_le=-1;
        int max_ri=-1;
        while(le<ri){
            max_le=max(max_le,height[le]);
            max_ri=max(max_ri,height[ri]);
            if(max_le<max_ri){
                h=(max_le-height[le]);
                sol+=h;
                le=le+1;
                }else{
                h=(max_ri-height[ri]);
                sol+=h;
                ri=ri-1;
            }
            
        }
        return sol;
        
    }
};
class Solution {
    vector<int> leftmax(vector<int>& height,int n){
        vector<int>lefttmax(n);
        lefttmax[0]=height[0];
        for(int i=1;i<n;i++){
            lefttmax[i]=max(lefttmax[i-1],height[i]);
        }
        return lefttmax;
    }

    vector<int> rightmax(vector<int>& height,int n){
        vector<int> righttmax(n);
        righttmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--) {
            righttmax[i]=max(righttmax[i+1],height[i]);  
        }
        return righttmax;
    }

public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> le_max=leftmax(height,n);
        vector<int> ri_max=rightmax(height,n);

        int sol=0;
        for (int i=0;i<n;i++) {
            int h=min(le_max[i],ri_max[i])-height[i];
            sol+=h;
        }

        return sol;
    }
};

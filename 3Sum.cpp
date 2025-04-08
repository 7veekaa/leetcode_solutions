#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>>sol;

    void twosum(vector<int>& nums,int twosumsum,int i,int j){
        while(i<j){
            if (nums[i]+nums[j]>twosumsum){
                j--;
            }else if(nums[i]+nums[j]<twosumsum){
                i++;
            }else{
                sol.push_back({-twosumsum,nums[i],nums[j]});

               
                while(i<j && nums[i]==nums[i+1])i++;
                while(i<j && nums[j]==nums[j-1])j--;

                i++;
                j--;
            }
            }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if (n<3) {
            return{};
        }

        for (int i=0; i<n-2; i++) {
            if (i>0 && nums[i]==nums[i-1]){
                continue;  
            }

            int twosumsum=-nums[i];
            twosum(nums,twosumsum,i+1,n-1);
        }

        return sol;
    }
};

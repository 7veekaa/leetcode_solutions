class Solution {
#define ll long long
public:
    long long minimumDifference(vector<int>& nums) {
        ll n=nums.size();
        priority_queue<ll,vector<ll>,greater<ll>>checkpoint;
        ll ri_sum=0;
        vector<ll>right_maxsum(n,0);
        for(ll i=n-1;i>=n/3;--i){
            checkpoint.push(nums[i]);
            ri_sum+= nums[i];
            if(checkpoint.size()>n/3){
                ri_sum-= checkpoint.top();
                checkpoint.pop();
            }
            if(checkpoint.size()==n/3)
                right_maxsum[i] = ri_sum;
        }
        priority_queue<ll>checkpointtwo;
        ll sol=LLONG_MAX;
        ll le_sum=0;
        for(ll i=0;i<2*n/3;++i){
            checkpointtwo.push(nums[i]);
            le_sum+= nums[i];
            if(checkpointtwo.size()>n/3){
                le_sum-= checkpointtwo.top();
                checkpointtwo.pop();
            }
            if(checkpointtwo.size()==n/3)
                sol=min<ll>(sol, le_sum - right_maxsum[i+1]);
        }return sol;
    }
};
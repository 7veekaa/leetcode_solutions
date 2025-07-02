#define ll long long
class Solution {
public:
    ll M =1e9+7;

    int possibleStringCount(string word, int k) {
        int n=word.size(), ptr = 1;
        ll all=1;
        vector<int>freq;

        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                ptr++;
            }else{
                //case of new char
                all=(all * ptr) % M; //updated
                freq.push_back(ptr-1); // leaving one for the min feasible string formation 
                ptr=1; //resetting counter for new char 
            }
        }

        all=(all*ptr) % M;
        freq.push_back(ptr-1);

        int min_feasible=freq.size();
        if(k<=min_feasible) return all;

        k -= min_feasible;
        vector<ll>dp(k, 0);
        dp[0]=1;
         for(int x : freq) {
            vector<ll> pref(k, 0);
            pref[0]=dp[0];
            for(int i=1;i<k;i++){
                pref[i]=(pref[i-1]+dp[i]) % M;
            }
            for(int i=0;i<k;i++){
                if (i-x-1>= 0)
                    dp[i] = (pref[i] - pref[i-x-1] + M)%M;
                else
                    dp[i] = pref[i];
            }
        }

        int sol=0;
        for(ll val:dp)sol = (sol+val) % M;

        return (all-sol + M) % M;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int>sol;
        vector<int>checkpoint(26,0);
        for(int i=0;i<n;i++){
            int last_occurrence=s[i]-'a';
            checkpoint[last_occurrence]=i;
            
        }
        int ri=0;
        while(ri<n){
            int last=checkpoint[s[ri]-'a'];

            int le=ri;

            while(le<last){
                last=max(last, checkpoint[s[le]-'a']);
                le++;
            }
            sol.push_back(le-ri+1);
            ri=le+1;
        }
        return sol;
        
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>checkpoint(26,0);
        for(char& ch:tasks){
            checkpoint[ch-'A']++;
        }
        int sol=0;
        priority_queue<int>maxx; 
        for(int i=0;i<26;i++){
            if(checkpoint[i]>0){
                maxx.push(checkpoint[i]);
            }
        }
        while(!maxx.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!maxx.empty()){
                int freq=maxx.top();
                maxx.pop();
                freq--;
                temp.push_back(freq);
                }

            }
            for(int &freq:temp){
                if(freq>0){
                    maxx.push(freq);
                }
            }
            if(maxx.empty()){
                sol+=temp.size();
            }else{
                sol+=n+1;
            }
        }
        return sol;
        
    }
};
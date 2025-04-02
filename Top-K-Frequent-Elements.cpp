class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> checkpoint;
        for(int num:nums) {
         checkpoint[num]++;  
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mh;
        for(auto& log:checkpoint){
            mh.push({log.second,log.first});
            if(mh.size()>k){
                mh.pop();
            }

        }
        vector<int>sol;
        while(!mh.empty()){
            sol.push_back(mh.top().second);
            mh.pop();
        }
        return sol;
        
    }
};
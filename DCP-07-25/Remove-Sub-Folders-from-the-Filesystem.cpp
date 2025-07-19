class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
       unordered_set<string> checkpoint(folder.begin(), folder.end());
       vector<string> sol;
       for(string& current: folder){
        bool is=false;
        string temp=current;
        while(!current.empty()){
            auto last=current.find_last_of('/');
            current=current.substr(0, last);
            if(checkpoint.find(current)!=checkpoint.end()){
                is=true;
                break;

            }
        }
        if(!is){
            sol.push_back(temp);
        }

       }
       return sol;

    }
};
class Solution {
//for backtracking -
    //validating
    //adding 
    //updating
    //return processing
    //restoring for recursive call

    private:
    int backtrack(unordered_map<char,int>& times){
        int addup=0;
        for (auto& [ch, f] : times) { 
            if(f>0){
                addup++;  
                times[ch]--; 
                addup += backtrack(times);  
                times[ch]++;  
            }
    }
    return addup;
    }

public:
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> times;
        for(char c:tiles) times[c]++;
        return backtrack(times);


    
    }
};
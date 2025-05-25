class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>checkpoint;
        int count_sol=0;
         for(string& word:words){
            string partial_pal=word;
            swap(partial_pal[0],partial_pal[1]);
            if(checkpoint[partial_pal]>0){
                count_sol+=4;
                checkpoint[partial_pal]--;}else{
                checkpoint[word]++;
                }
        }for(auto& it:checkpoint){
            string w=it.first;
            int c=it.second;
            if(w[0]==w[1]&&c>0){
                count_sol+=2;
                break;
            }
         }return count_sol;
    }
};

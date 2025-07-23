class Solution {
public:
    int maximumGain(string s,int x,int y){
        int sol=0;
        string first=(x>y)?"ab":"ba";
        string second=(x>y)?"ba":"ab";
        int firstScore=max(x,y);
        int secondScore=min(x,y);
        string afterFirst;
        int firstCount=remove_s(s,first,afterFirst);
        sol+=firstCount*firstScore;
        int secondCount=remove_s(afterFirst,second,afterFirst);
        sol+=secondCount*secondScore;
        return sol;
    }

    int remove_s(const string &s,const string &match,string &out){
        stack<char>checkpoint;
        int count=0;
        for(char ch:s){
            if(!checkpoint.empty()&&checkpoint.top()==match[0]&&ch==match[1]){
                checkpoint.pop();
                count++;
            }else{
                checkpoint.push(ch);
            }
        }
        string temp;
        while(!checkpoint.empty()){
            temp.push_back(checkpoint.top());
            checkpoint.pop();
        }
        reverse(temp.begin(),temp.end());
        out=temp;
        return count;
    }
};

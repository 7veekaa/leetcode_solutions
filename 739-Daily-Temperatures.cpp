class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int>s;
        int size=temperatures.size();
        vector<int> answer(size);
        for(int i=size-1;i>=0;i--){ //starting from end of stack to build my answer
            while(!s.empty() && temperatures[i]>=temperatures[s.top()]){ //non empty stack and jo value check kr rhe that is greater than stack's top, pop it out also we talking INDICES here
                s.pop();
            }
            if(s.empty()){ //case for first element, if stack is empty, just push 0 
                answer[i]=0;
            }else{
                answer[i]=s.top()-i; //difference in indices indicating number of days 
            }
            s.push(i);
        }
        return answer;
    }
};
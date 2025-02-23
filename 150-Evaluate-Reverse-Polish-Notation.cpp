#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
    // question instantly reminded me of prefix and postfix notations.
    // while example 1 is very easy and can be solved with the logic here. i wanna try pre and post and their dry runs too
    // sol:
    // initiate stack
    
    // traverse through string array
    // apply stoi function
    // while i != +,-,*,/.. st.push()
    // if and else if condition for all operators,, while(!st.empty), st.pop()
    // int result = st.pop + st.pop();
    // st.push(result);
    // finally return st.top();
    int followup = 0;
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sol;  
        
        for (int i = 0; i < tokens.size(); i++) { 
            if (tokens[i] != \+\ && tokens[i] != \-\ && tokens[i] != \*\ && tokens[i] != \/\) {
                sol.push(stoi(tokens[i])); 
            } 
            else {
                int b = sol.top(); sol.pop(); 
                int a = sol.top(); sol.pop();
                
        if (tokens[i] == \+\) {
                    followup = a + b;
                } 
        else if (tokens[i] == \-\) { 
                    followup = a - b;
                } 
        else if (tokens[i] == \*\) {
                    followup = a * b;
                } 
        else if (tokens[i] == \/\) {
                    followup = a / b;
                }
                sol.push(followup);
            }
        }
           return sol.top();
    }
};

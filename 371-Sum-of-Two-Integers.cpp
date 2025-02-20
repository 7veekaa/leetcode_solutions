class Solution {
public:
    int getSum(int a, int b) {
        if(b==0){
            return a;
        }
        int XOR=a^b;
         unsigned int op_post_XOR=(a&b)<<1;
         return getSum(XOR, op_post_XOR);
        
    }
};
class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n){
            int bit=n&1;
            if(bit==1) count++; 
            n=n>>1;
        }
        return count;
        
    }
};


//Optimal way is some brian something algo, brian kernighan-
/*class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            count++;  
            n = n & (n - 1); 
        }
        return count;
    }
};
*/
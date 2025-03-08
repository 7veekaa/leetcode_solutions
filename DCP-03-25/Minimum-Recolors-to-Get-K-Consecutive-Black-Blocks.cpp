class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int le=0;
        int ri=0;
        int whites=0;
        int sol=k;
        while(ri<blocks.size()){
           
           
            if(blocks[ri]=='W'){
                whites++;
            }
           
           
            if(ri-le+1==k){  
                sol=min(sol,whites);
                if(blocks[le]=='W'){  
                    whites--;
                }
               
                le++;  
            }
            ri++;  
        }
       
       
       
        return sol;
    }
};

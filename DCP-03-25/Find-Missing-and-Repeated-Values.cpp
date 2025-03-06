class Solution {
    //map<num, frq>
    //traverse till N^2
    //return {a,b}



    //Approach 2 - O(N^2)
    //logic in daily prob notes

public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int N=n*n;
        long long grids=0;       
        long long gridsqs=0;     

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grids+=grid[i][j];
                gridsqs+=(long long)grid[i][j]*(long long)grid[i][j]; 
            

            }
            
        }
        long long supposeds= (N*(N+1LL))/2; 
        long long supposedsqs=(N*(N+1LL)*(2*N+1LL))/6; //overflows cus performing normal arthematic on long long
        //what is ll i ll forget, hence -  long long automatically handles these large multiplications

        long long squaregap = gridsqs-supposedsqs;
        long long sumgap=grids-supposeds;

        int a=(squaregap/sumgap + sumgap)/2;
        int b=(squaregap/sumgap - sumgap)/2;
        return {a,b};
        
    }
};

class Solution {
public:
    vector<vector<string>>sol;
 bool safetomove(vector<string>& b,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(b[i][col]=='Q')return false;}
            for (int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(b[i][j]=='Q') return false;
        }
for (int i=row-1,j=col+1;i>=0&&j<n;i--,j++) {
            if(b[i][j]=='Q') return false;}
             return true;
    }

    void solve(vector<string>& b, int row, int n) {
        if(row==n){
            sol.push_back(b);
            return;
        }

        for(int col=0;col<n;col++){
            if(safetomove(b,row,col,n)){
                b[row][col]='Q';
                solve(b, row + 1,n);
                b[row][col]='.'; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> b(n, string(n,'.'));
        solve(b,0,n);
        return sol;
    }
};

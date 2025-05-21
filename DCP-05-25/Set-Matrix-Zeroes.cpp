class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool rowone_impact=false;
        bool colone_impact=false;

        
        for(int c=0;c<n;c++){
            if(matrix[0][c]==0){
                rowone_impact=true;
                break;
            }
        }
        for(int r=0;r<m;r++){
            if(matrix[r][0]==0){
                colone_impact=true;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(rowone_impact){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(colone_impact){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};

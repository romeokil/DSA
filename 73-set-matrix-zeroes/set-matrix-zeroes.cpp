class Solution {
public: 
    void putZero(int row,int col,int n,int m,vector<vector<int>>& visited){
        // wo saare row me 0 kr dete hai.
        for(int j=0;j<m;j++){
            visited[row][j]=0;
        }
        // wo saara column me 0 kr dete hai .
        for(int k=0;k<n;k++){
            visited[k][col]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    // chalo eska saaara row and column 0 se bhr do
                    putZero(i,j,n,m,visited);
                }
            }
        }
        // ab rest of visited matrix ko bhr dete hai.
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]!=0 && visited[i][j]!=0){
        //             visited[i][j]=matrix[i][j];
        //         }
        //     }
        // }
        // wapas visited waale se matrix me daal dete hai inplcae bola tha.
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         matrix[i][j]=visited[i][j];
        //     }
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0) {
                    matrix[i][j]=0;
                }
            }
        }
    }
};
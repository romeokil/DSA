class Solution {
public:
    void display(vector<vector<int>>& visited,int n,int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<"i->"<<i<<"j->"<<j<<" "<<visited[i][j]<<endl;
            }
        }
    }
    void paintrowandcol(int row,int col,vector<vector<int>>& visited,int n,int m){
        // pehle row ko rangte hai
        for(int i=0;i<n;i++){
            visited[i][col]=0;
        }
        // phir col ko rangte hai.
        for(int j=0;j<m;j++){
            visited[row][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // jo bhi row and column me zero mile uske baad function call kr diye
                if(matrix[i][j]==0){
                    paintrowandcol(i,j,visited,n,m);
                }
            }
        }
        // hmlog saara matrix se visited me daal dete hai non-zero values
        cout<<"visted array ko mark krne ke baad"<<endl;
        display(visited,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0 && visited[i][j]!=0){
                    visited[i][j]=matrix[i][j];
                }
            }
        }
        // ab wapas jb visited jb hmlog bhr diye toh wapas matrix me daal diye dete hai.
        cout<<"ab hmlog matrix se visited ki traf daal de rhe hai chizen";
        display(visited,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=visited[i][j];
            }
        }
    }
};
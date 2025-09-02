class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid){
        // out of bound check kr lo
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==-1){
            return ;
        }
        grid[i][j]=-1;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // for first row
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid);
            }
        }
        // for last row
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==1){
                dfs(n-1,j,grid);
            }
        }
        // for first column
        for(int j=0;j<n;j++){
            if(grid[j][0]==1){
                dfs(j,0,grid);
            }
        }
        // for last column
        for(int j=0;j<n;j++){
            if(grid[j][m-1]==1){
                dfs(j,m-1,grid);
            }
        }
        // ab aisa hai ki saara mark ho gy boundary ke through jo bhi land hoga 
        // wo hmlog cover kr chuke hai.
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};
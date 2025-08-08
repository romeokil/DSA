class Solution {
public:
    void display(vector<vector<int>>& dp){
        for(const vector<int>&v:dp){
            for(const int &e:v){
                cout<<e<<" ";
            }
            cout<<endl;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    // yaha pe obstacle hai
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 && j==0) || (dp[i][j]==0)) continue;
                int up= i>0 ? dp[i-1][j] :0;
                int left= j>0 ? dp[i][j-1]:0;
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};
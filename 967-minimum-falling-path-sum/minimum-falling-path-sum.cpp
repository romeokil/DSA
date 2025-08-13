class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        vector<vector<int>> dp(n,vector<int>(n,0));
        // dp array ko first row bhr lete hai.
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        // ab dekho hm baaki bhrte hai.
        int  minSum=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int diagonalleft=j-1>=0?dp[i-1][j-1]:9999;
                int directabove=dp[i-1][j];
                int diagonalright=j+1<n?dp[i-1][j+1]:9999;
                cout<<"diagonalleft"<<diagonalleft<<endl;
                cout<<"directabove"<<directabove<<endl;
                cout<<"diagonalriht"<<diagonalright<<endl;
                dp[i][j]=matrix[i][j]+min({diagonalleft,directabove,diagonalright});
                cout<<"dp"<<dp[i][j]<<endl;
                if(i==n-1){
                    minSum=min(minSum,dp[i][j]);
                }
            }
        }
        return minSum;
    }
};
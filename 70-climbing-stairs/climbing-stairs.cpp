class Solution {
public:
    int solve(int i,int n,vector<int>& dp){

        if(i>=n){
            if(i==n) return 1;
            else return 0;
        }
        if(dp[i]!=-1) return dp[i];
        // ya toh ek step chado
        int oneStep=solve(i+1,n,dp);

        // ya ek saath do step chado.
        int twoStep=solve(i+2,n,dp);

        return dp[i]=oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(0,n,dp);
    }
};
class Solution {
public:
    int solve(int steps,int n,vector<int>& dp){
        if(steps>=n){
            if(steps==n) return 1;
            return 0;
        }
        if(dp[steps]!=-1) return dp[steps];
        // ya toh hm ek step le skte hai
        int one_step=solve(steps+1,n,dp);
        // ya dusra bhi le skte hai.
        int two_step=solve(steps+2,n,dp);
        return dp[steps]=one_step+two_step;
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return solve(0,n,dp);
    }
};
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // agr ek bhi step ni hua toh dp[0]=0;
        // agr ek step hua toh dp[1]=1;
        // agr 2 step hua toh dp[2]=1step+1step, 2 step =total 2 different approach =2 steps;
        if(n==0 || n==1 || n==2) return n; 
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
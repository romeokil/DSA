class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,int fee,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int take_case=-prices[i]+solve(i+1,0,prices,fee,dp);
            int skip_case=solve(i+1,1,prices,fee,dp);
            return dp[i][buy]=max(take_case,skip_case);
        }
        else{
            int take_case=(prices[i]-fee)+solve(i+1,1,prices,fee,dp);
            int skip_case=solve(i+1,0,prices,fee,dp);
            return dp[i][buy]=max(take_case,skip_case);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,fee,dp);
    }
};
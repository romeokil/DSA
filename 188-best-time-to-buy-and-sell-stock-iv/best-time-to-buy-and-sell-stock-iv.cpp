class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,int k,vector<vector<vector<int>>>& dp){
        if(k==0) return 0;
        if(i>=prices.size()) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int take_case=0,skip_case=0;
        if(buy){
            int take_case=-prices[i]+solve(i+1,0,prices,k,dp);
            int skip_case=solve(i+1,1,prices,k,dp);
            return dp[i][buy][k]=max(take_case,skip_case);
        }
        else{
            int take_case=prices[i]+solve(i+1,1,prices,k-1,dp);
            int skip_case=solve(i+1,0,prices,k,dp);
            return dp[i][buy][k]=max(take_case,skip_case);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,prices,k,dp);
    }
};
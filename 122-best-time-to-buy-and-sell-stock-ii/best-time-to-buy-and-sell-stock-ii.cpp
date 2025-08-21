class Solution {
public:
    int solve(int i,vector<int>& prices,int buy,vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        int take_case=0,skip_case=0;
        if(buy){
            // kharid liye or ni bhi kharid skte the right.
            take_case=max(-prices[i]+solve(i+1,prices,0,dp),solve(i+1,prices,1,dp));
        }   
        // bech skte hai or ni bhi bech skte hai right.
        else skip_case=max(prices[i]+solve(i+1,prices,1,dp),solve(i+1,prices,0,dp));
        return dp[i][buy]=max(take_case,skip_case);
    }
    int maxProfit(vector<int>& prices) {
        // index,vector,buy
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,prices,1,dp);
    }
};
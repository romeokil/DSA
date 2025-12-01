class Solution {
public:
    int solve(int i,vector<int>& nums,int prev,vector<vector<int>>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take_case=0,skip_case=0;
        if(prev==-1 || nums[i]>nums[prev]){
            take_case=1+solve(i+1,nums,i,dp);
        }
        skip_case=solve(i+1,nums,prev,dp);
        return dp[i][prev+1]=max(take_case,skip_case);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=-1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums,prev,dp);
    }
};
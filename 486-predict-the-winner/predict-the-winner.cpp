class Solution {
public:
    int findaliceBobScoreDiff(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i=nums[i]-findaliceBobScoreDiff(i+1,j,nums,dp);
        int take_j=nums[j]-findaliceBobScoreDiff(i,j-1,nums,dp);

        return dp[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        // memoize kr de rhe hai bs.
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int aliceBobScoreDiff=findaliceBobScoreDiff(0,n-1,nums,dp);
        if(aliceBobScoreDiff>=0) return true;
        return false;
        
    }
};
class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx>=nums.size()) return 0;

        if(dp[idx]!=-1) return dp[idx];
        // ek ghr lete hai ek ghr chorte hai 
        int take_case=0,skip_case=0;
        take_case=nums[idx]+solve(idx+2,nums,dp);
        skip_case=solve(idx+1,nums,dp);
        return dp[idx]=max(take_case,skip_case);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,nums,dp);
    }
};
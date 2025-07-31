class Solution {
public:
    int solve(int idx,int last_index,vector<int>& nums,vector<int> &dp){
        if(idx>=last_index){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int take_case=nums[idx]+solve(idx+2,last_index,nums,dp);
        int skip_case=solve(idx+1,last_index,nums,dp);
        return dp[idx]=max(take_case,skip_case);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int firstwalaghrliye=solve(0,n-1,nums,dp1);
        int lastwalaghrliye=solve(1,n,nums,dp2);
        return max(firstwalaghrliye,lastwalaghrliye);
    }
};
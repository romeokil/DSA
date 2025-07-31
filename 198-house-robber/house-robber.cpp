class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp(n+1,-1);
        dp[0]=0,dp[1]=nums[0],dp[2]=max(nums[0],nums[1]);
        for(int i=3;i<=n;i++){
            int take_case=nums[i-1]+dp[i-2];
            int skip_case=dp[i-1];
            dp[i]=max(take_case,skip_case);
        }
        return dp[n];
    }
};
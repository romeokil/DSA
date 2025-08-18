class Solution {
public:
    bool solve(int i,int cursum,vector<int>& nums,int finalsum,vector<vector<int>>& dp){
        if(cursum==finalsum){
            return true;
        }
        if(dp[i][cursum]!=-1) return dp[i][cursum]; 
        if(i>=nums.size()) return false;
        bool take_case=false,skip_case=false;
        if(cursum+nums[i]<=finalsum){
            take_case=solve(i+1,cursum+nums[i],nums,finalsum,dp);
        }
        skip_case=solve(i+1,cursum,nums,finalsum,dp);
        return dp[i][cursum]=take_case || skip_case;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum,-1));
        return solve(0,0,nums,sum/2,dp);
    }
};
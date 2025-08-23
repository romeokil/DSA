class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxlen=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(nums[j]<nums[i] && dp[i]==dp[j]+1){
                    count[i]+=count[j];
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        // finding the count;
        int totalCount=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxlen){
                totalCount+=count[i];
            }
        }
        return totalCount;
    }
};
class Solution {
public:
    void display(vector<int>& dp){
        for(int &it:dp){
            cout<<"it"<<it<<endl;
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxlen=1;
        // hm eslie 1 se initialize kiye qki hmko
        // pata hai hr ek no apne me lis hai.
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    if(dp[i]>maxlen){
                        maxlen=dp[i];
                    }
                }
            }
        }
        display(dp);
        return maxlen;
    }
};
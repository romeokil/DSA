class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int maxlen=1;
        int last_chosen_index=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
                if(dp[i]>maxlen){
                    maxlen=dp[i];
                    last_chosen_index=i;
                }
            }
        }
        while(last_chosen_index!=-1){
            temp.push_back(nums[last_chosen_index]);
            last_chosen_index=prev[last_chosen_index];
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
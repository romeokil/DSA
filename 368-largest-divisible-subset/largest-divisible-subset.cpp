class Solution {
public:
    void display(vector<int> ans){
        for(int no:ans){
            cout<<no<<" ";
        }
        cout<<endl;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        vector<int> result;
        int maxlen=0;
        int last_chosen_index=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    cout<<"nums[i]"<<nums[i]<<endl;
                    cout<<"nums[j]"<<nums[j]<<endl;
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            // dp[i] me maximum aa gy hoga ki es length tk hmlog 
            // kitna largest divisible subset bana skte hai.
            if(dp[i]>maxlen){
                maxlen=dp[i];
                last_chosen_index=i;
            }
        }
        display(dp);
        display(prev);
        while(last_chosen_index!=-1){
            result.push_back(nums[last_chosen_index]);
            last_chosen_index=prev[last_chosen_index];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        int count=1;
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
            if((maxi-mini)>k){
                count++;
                maxi=max(maxi,nums[i]);
                mini=max(maxi,nums[i]);
            }
        }
        return count;
    }
};
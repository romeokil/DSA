class Solution {
public:
    bool checkdistinct(unordered_map<int,int>& um){
        for(const pair<int,int>& p:um){
            if(p.second>1) return false;
        }
        return true;
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        long long cursum=0,maxsum=INT_MIN;
        unordered_map<int,int> um;
        while(j<n){
            cursum+=nums[j];
            um[nums[j]]++;
            if(i<j && (j-i+1)>k){
                cursum-=nums[i];
                um[nums[i]]--;
                if(um[nums[i]]==0) um.erase(nums[i]);
                i++;
            }
            if((j-i+1)==k && um.size()==k){
                maxsum=max(maxsum,cursum);
            }
            j++;
        }
        return maxsum==INT_MIN?0:maxsum;
    }
};
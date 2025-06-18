class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cursum=0,count=0;
        unordered_map<int,int> um;
        um[0]=1;
        for(int i=0;i<n;i++){
            cursum+=nums[i];
            count+=um[cursum-k];
            um[cursum]+=1;
        }
        return count;
    }
};
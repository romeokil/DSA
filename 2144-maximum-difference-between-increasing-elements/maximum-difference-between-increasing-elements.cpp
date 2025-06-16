class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int curdiff=0;
        int maxdiff=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j && nums[i]<nums[j]){
                    curdiff=nums[j]-nums[i];
                    maxdiff=max(maxdiff,curdiff);
                }
            }
        }
        return maxdiff==INT_MIN?-1:maxdiff;
    }
};
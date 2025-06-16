class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int curdiff=0;
        int n=nums.size();
        int mini=nums[0];
        int mindiff=-1;
        for(int i=1;i<n;i++){
            int curdiff=nums[i]-mini;
            if(curdiff>0) mindiff=max(mindiff,curdiff);
            mini=min(mini,nums[i]);
        }
        return mindiff;
    }
};
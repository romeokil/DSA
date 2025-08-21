class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int cursum=0,minlen=INT_MAX;
        while(j<n){
            cursum+=nums[j];
            while(i<=j && cursum>=target){
                minlen=min(minlen,(j-i+1));
                cursum-=nums[i];
                i++;
            }
            j++;
        }
        return minlen==INT_MAX?0:minlen;
    }
};
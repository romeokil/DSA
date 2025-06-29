#define MOD 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=n-1;
        int count=0;
        vector<int> power(n+1,1);
        for(int i=1;i<=n;i++){
            power[i]=(power[i-1]*2LL)%MOD;
        }
        while(low<=high){
            if(nums[low]+nums[high]<=target){
                int diff=(high-low);
                count=(count%MOD+power[diff])%MOD;
                low++;
            }
            else{
                high--;
            }
        }
        return count%MOD;
    }
};
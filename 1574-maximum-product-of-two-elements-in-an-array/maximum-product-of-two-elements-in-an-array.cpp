class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curprod=0,maxprod=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                curprod=((nums[i]-1)*(nums[j]-1));
                maxprod=max(maxprod,curprod);
            }
        }
        return maxprod;
    }
};
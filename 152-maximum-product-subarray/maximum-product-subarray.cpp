class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxprod=INT_MIN;
        for(int i=0;i<n;i++){
            int curprod=1;
            for(int j=i;j<n;j++){
                curprod*=nums[j];
                if(curprod>maxprod){
                    maxprod=curprod;
                }
            }
        }
        return maxprod;
    }
};
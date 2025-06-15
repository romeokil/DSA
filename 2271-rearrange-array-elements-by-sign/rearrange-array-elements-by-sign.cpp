class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        if(n==1) return {nums[0]};
        int positiveindex=0;
        int negativeindex=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                result[positiveindex]=nums[i];
                positiveindex+=2;
            }
            else{
                result[negativeindex]=nums[i];
                negativeindex+=2;
            }
        }
        return result;
    }
};
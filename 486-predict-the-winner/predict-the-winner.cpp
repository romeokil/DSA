class Solution {
public:
    int findaliceBobScoreDiff(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(i==j) return nums[i];
        int take_i=nums[i]-findaliceBobScoreDiff(i+1,j,nums);
        int take_j=nums[j]-findaliceBobScoreDiff(i,j-1,nums);

        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int aliceBobScoreDiff=findaliceBobScoreDiff(0,n-1,nums);
        if(aliceBobScoreDiff>=0) return true;
        return false;
        
    }
};
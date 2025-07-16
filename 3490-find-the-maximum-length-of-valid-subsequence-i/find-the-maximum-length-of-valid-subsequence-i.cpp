class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // mik bhaiya bole ki bhai dekho tm given equation ko dekho
        int cntEven=0,cntOdd=0,cntAlternate=0;
        int prevparity=0;
        if(nums[0]%2==0){
            cntEven++;
            prevparity=nums[0]%2;
        }
        else {
            cntOdd++;
            prevparity=nums[0]%2;
        }
        cntAlternate++;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==0) cntEven++;
            else cntOdd++;
            if(nums[i]%2!=prevparity){
                cntAlternate++;
                prevparity=nums[i]%2;
            }
        }
        // cout<<"cntEven"<<cntEven<<endl;
        // cout<<"cntOdd"<<cntOdd<<endl;
        // cout<<"cntAlternating"<<cntAlternate<<endl;
        return max({cntEven,cntOdd,cntAlternate});
    }
};
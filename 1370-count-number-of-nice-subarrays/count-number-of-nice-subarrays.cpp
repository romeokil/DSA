class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int countOdd=0;
        int result=0;
        int countEven=0;
        while(j<n){
            if(nums[j]%2!=0) countOdd++;
            while(i<j && ((nums[i]%2==0 && countOdd==k) || countOdd>k)){
                if(nums[i]%2==0) countEven++;
                if(nums[i]%2!=0) {
                    countEven=0;
                    countOdd--;
                }
                i++;
            }
            // cout<<"countEven="<<countEven<<endl;
            if(countOdd==k) result+=countEven+1;
            // cout<<"result="<<result<<endl;
            j++; 
        }
        return result;
    }
};
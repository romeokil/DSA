class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int i=0,j=0;
        int countOnes=0;
        int cursum=0,count=0;
        while(j<n){
            cursum+=nums[j];
            while(i<j && (nums[i]==0  || cursum>goal)){
                if(nums[i]==0) countOnes++;
                else countOnes=0;
                cursum-=nums[i];
                i++;
            }
            if(cursum==goal) count+=countOnes+1;
            cout<<"countOnes"<<countOnes<<endl;
            cout<<"count"<<count<<endl;
            j++;
        }
        return count;
    }
};
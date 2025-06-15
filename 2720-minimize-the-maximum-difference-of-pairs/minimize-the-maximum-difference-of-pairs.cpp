class Solution {
public:
    bool isPossible(vector<int>& nums,int p,int cd){
        int currentcd=0;
        int countPairs=0;
        int i=0,n=nums.size();
        while(i<n-1){
            if(abs(nums[i]-nums[i+1])<=cd){
                countPairs++;
                i=i+2;
            }
            else i++;
        }
        return countPairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,ans=-1,high=nums[n-1]-nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(nums,p,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
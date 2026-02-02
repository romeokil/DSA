class Solution {
public:
    bool isPossible(int mid,vector<int>& citations){
        int count=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=mid) count++;
        }
        return count>=mid;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int low=1,high=n,mid=0,ans=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(isPossible(mid,citations)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
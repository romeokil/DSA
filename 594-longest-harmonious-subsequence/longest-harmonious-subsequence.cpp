class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            um[nums[i]]++;
        }
        // ab map se nikalwate hai
        int maxlen=INT_MIN;       
        for(int i=0;i<n;i++){
            int min=nums[i];
            int max=min+1;
            if(um.find(max)!=um.end()){
                int minFreq=um[min];
                int maxFreq=um[max];
                int curlen=minFreq+maxFreq;
                if(curlen>maxlen){
                    maxlen=curlen;
                }
            }
        }
        return maxlen==INT_MIN?0:maxlen;
    }
};
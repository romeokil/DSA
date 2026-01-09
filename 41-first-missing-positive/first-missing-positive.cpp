class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                mini=min(mini,nums[i]);
                maxi=max(maxi,nums[i]);
                st.insert(nums[i]);
            }
        }
        if(mini==INT_MAX && maxi==INT_MIN) return 1;
        for(int i=1;i<=maxi;i++){
            if(st.find(i)==st.end()) return i;
        }
        return maxi+1;
    }
};
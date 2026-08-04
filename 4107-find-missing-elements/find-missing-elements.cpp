class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        unordered_set<int> st;
        vector<int> result;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            st.insert(nums[i]);
        }
        for(int i=mini;i<=maxi;i++){
            if(st.find(i)==st.end()) result.push_back(i);
        }
        return result;
    }

};
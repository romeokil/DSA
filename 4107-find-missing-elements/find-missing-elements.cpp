class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        vector<int> result;
        // find maximum and minimum 
        int max=*max_element(nums.begin(),nums.end());
        int min=*min_element(nums.begin(),nums.end());
        // putting nums so that we can find out if it is already present or not
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=min;i<=max;i++){
            if(st.find(i)==st.end()) result.push_back(i);
        }
        return result;
    }
};
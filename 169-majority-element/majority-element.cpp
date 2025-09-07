class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            um[nums[i]]++;
        }
        for(const pair<int,int>& p:um){
            if(p.second>(n/2)) return p.first;
        }
        return -1;
    }
};
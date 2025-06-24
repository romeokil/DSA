class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                um[i]=key;
            }
        }
        // now store the result;
        vector<int> temp;
        for(int i=0;i<n;i++){
            int x=i;
            for(const pair<int,int>& p:um){
                int y=p.first;
                int value=p.second;
                if(abs(x-y)<=k){
                    temp.push_back(x);
                    break;
                }
            }
        }
        return temp;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> temp;
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            int remainingno=target-nums[i];
            if(um.find(remainingno)!=um.end()){
                temp.push_back(i);
                temp.push_back(um[remainingno]);
                break;
            }
            um[nums[i]]=i;
        }   
        return temp;
    }
};
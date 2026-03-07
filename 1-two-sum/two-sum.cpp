class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> result;
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            int currentElement=nums[i];
            if(um.find(target-currentElement)!=um.end()) {
                result.push_back(i);
                result.push_back(um[target-currentElement]);
                break;
            }
            um[currentElement]=i;
        }
        return result;
    }
};
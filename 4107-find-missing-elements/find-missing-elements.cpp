class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(101,0);
        vector<int> result;
        sort(nums.begin(),nums.end());
        int largest=nums[n-1];
        int smallest=nums[0];
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i=smallest;i<=largest;i++){
            if(freq[i]==0) result.push_back(i);
        }
        return result;

    }
};
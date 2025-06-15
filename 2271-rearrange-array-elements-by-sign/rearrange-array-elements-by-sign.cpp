class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        int p=nums.size();
        for(int i=0;i<p;i++){
            if(nums[i]<0) negative.push_back(nums[i]);
            else positive.push_back(nums[i]);
        }
        int m=positive.size();
        int n=negative.size();
        vector<int> result(m+n);
        int i=0;
        for(int j=0;j<m;j++){
            result[i]=positive[j];
            i=i+2;
        }
        i=1;
        for(int k=0;k<n;k++){
            result[i]=negative[k];
            i=i+2;
        }   
        return result;
    }
};
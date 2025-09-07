class Solution {
public:
    void reverse(int firstIndex,int secondIndex,vector<int>& nums){
        int i=firstIndex,j=secondIndex;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        // in place 
        // single element me ky hi reverse kre.
        int n=nums.size();
        k=k%n;
        reverse(0,n-1,nums);
        reverse(0,k-1,nums);
        reverse(k,n-1,nums);
    }
};
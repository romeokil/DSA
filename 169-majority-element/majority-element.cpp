class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithm
        int n=nums.size();
        int majority=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==majority){
                count++;
            }
            else if(count==0){
                majority=nums[i];
                count=1;
            }
            else count--;
        }
        return majority;
    }
};
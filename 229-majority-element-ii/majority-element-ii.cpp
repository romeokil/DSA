class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // moore's voting algorithm.
        int n=nums.size();
        int majority1=-1;
        int count1=0;
        int majority2=-1;
        int count2=0;
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(nums[i]==majority1){
                count1++;
            }
            else if(nums[i]==majority2){
                count2++;
            }
            else if(count1==0){
                majority1=nums[i];
                count1=1;
            }
            else if(count2==0){
                majority2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        // ab verify kr lete hai ki shi me hai ki ni.
        int freq1=0;
        int freq2=0;
        for(int num:nums){
            if(num==majority1) freq1++;
            else if(num==majority2) freq2++;
        }
        if(freq1>(n/3)){
            temp.push_back(majority1);
        }
        if(freq2>(n/3)){
            temp.push_back(majority2);
        }
        return temp;
    }
};
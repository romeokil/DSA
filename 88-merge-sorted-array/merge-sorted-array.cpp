class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec(n+m,0);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                vec[k++]=nums1[i++];
            }
            else{
                vec[k++]=nums2[j++];
            }
        }
        while(i<m){
            vec[k++]=nums1[i++];
        }
        while(j<n){
            vec[k++]=nums2[j++];
        }
        nums1=vec;
    }
};
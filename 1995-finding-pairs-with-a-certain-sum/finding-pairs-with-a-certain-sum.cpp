class FindSumPairs {
public:
    // bahar q define kr rhe hai qki hmko add and count function me uska access chahiye.  
    vector<int> vec1;
    vector<int> vec2;
    unordered_map<int,int> um;  
    // ye niche wala constructor hai or constructor se hm chizen initialize krte hai

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1=nums1;
        vec2=nums2;
        // or hmlog vec2 ko daalege map me
        for(int i=0;i<vec2.size();i++){
            um[vec2[i]]++;
        }    
    }
    void add(int index, int val) {
        um[vec2[index]]--;
        if(um[vec2[index]]==0) um.erase(vec2[index]);
        vec2[index]+=val;
        um[vec2[index]]++;
    }
    
    int count(int tot) {
        // ye jo tm likhe ho ye bhi shi hai but O(n2) hai or tmko pair hi nikalna 
        // hai toh phir two sum wala technique lagao na.

        // int cntPairs=0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         if(nums1[i]+nums2[j]==tot) cntPairs++;
        //     }
        // }
        // return cntPairs;

        int cntPairs=0;
        // iterate in the vec1 
        for(int i=0;i<vec1.size();i++){
            // agr map me mil gy toh phir thk hai.
            if(um.find(tot-vec1[i])!=um.end()){
                cntPairs+=um[tot-vec1[i]];
            }
        }
        return cntPairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
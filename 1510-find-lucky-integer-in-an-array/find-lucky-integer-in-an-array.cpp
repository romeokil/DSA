class Solution {
public:
    int findLucky(vector<int>& arr) {
        // unordered_map<int,int> um;
        // for(int i=0;i<arr.size();i++){
        //     um[arr[i]]++;
        // }
        // int luckynumber=-1;
        // // iterate in the map
        // for(const pair<int,int>& p:um){
        //     if(p.first==p.second){
        //         luckynumber=max(luckynumber,p.first);
        //     }
        // }
        // return luckynumber;

        // without using extra space
        int luckynumber=-1;
        int n=arr.size();
        vector<int> vec(501,0);
        for(int i=0;i<n;i++){
            vec[arr[i]]++;
        }
        for(int i=1;i<501;i++){
            if(vec[i]!=0 && i==vec[i]){
                luckynumber=max(luckynumber,i);
            }
        }
        return luckynumber;
    }   
};
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int i=0;i<arr.size();i++){
            um[arr[i]]++;
        }
        int luckynumber=-1;
        // iterate in the map
        for(const pair<int,int>& p:um){
            if(p.first==p.second){
                luckynumber=max(luckynumber,p.first);
            }
        }
        return luckynumber;
    }
};
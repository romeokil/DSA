class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> mergedindex;
        for(int i=0;i<n;i++){
            mergedindex.push_back({nums[i],i});
        }
        // hmlog sort kr diye hai by value taaki hmlog k amount of bada element le ske.
        // sort(mergedindex.begin(),mergedindex.end(),[const pair<int,int>& a,const pair<int,int>& b]{
        //     return a.first>b.second; 
        // })
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // default max heap hota apne ko min heap me krna hai.
        for(int i=0;i<mergedindex.size();i++){
            pq.push({mergedindex[i].first,mergedindex[i].second});
            if(pq.size()>k) pq.pop();
        }
        mergedindex.clear();
        while(!pq.empty()){
            pair<int,int> p=pq.top();pq.pop();
            mergedindex.push_back(p);
        }
        sort(mergedindex.begin(),mergedindex.end(),[&](const pair<int,int>& a,const pair<int,int>& b){
            return a.second<b.second;
        });
        vector<int> result;
        for(int i=0;i<mergedindex.size();i++){
            result.push_back(mergedindex[i].first);
        }
        return result;
    }
};
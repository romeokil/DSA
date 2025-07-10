class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        result.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            int prevstart=result.back()[0];
            int prevend=result.back()[1];
            int curstart=intervals[i][0];
            int curend=intervals[i][1];
            if(prevend>=curstart){
                result.pop_back();
                result.push_back({prevstart,curend>prevend?curend:prevend});
            }
            else result.push_back(intervals[i]);
        }
        return result;
    }
};
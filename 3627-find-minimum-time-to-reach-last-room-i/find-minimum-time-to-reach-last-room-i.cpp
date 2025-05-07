class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // bhai dekho esme bhi source se destionation ka shortest path chahiye
        // or single source wala chiz hai toh dijkstra's algo
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>> result(n,vector<int>(m,INT_MAX-1));
        vector<vector<int>> directions={{0,-1},{0,1},{-1,0},{1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,     greater<pair<int,pair<int,int>>>> pq;
        // bhai dekho {currentTime,{i_index,j_index}};
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int currentTime=it.first;
            pair<int,int> cells=it.second;
            int i=cells.first;
            int j=cells.second;
            if(i==n-1 && j==m-1){
                return currentTime;
            }
            // dekhte hai 4 direction me
            for(auto dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];
                if(i_>=0 && i_<n && j_>=0 && j_<m){
                    int wait=max(moveTime[i_][j_]-currentTime,0);
                    int finaltime=wait+currentTime+1;
                    if(result[i_][j_]>finaltime){
                        result[i_][j_]=finaltime;
                        pq.push({finaltime,{i_,j_}});
                    }
                } 
            }
        }
        return -1;
    }
};
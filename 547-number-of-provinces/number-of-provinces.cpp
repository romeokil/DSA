class Solution {
public:
    void dfs(int source,vector<vector<int>>& um,vector<bool>& visited){
        visited[source]=true;
        // explore its neighbour
        for(int &v:um[source]){
            if(!visited[v]){
                dfs(v,um,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        // ek or ghatiya approach 
        vector<bool> visited(n,false);
        // lets make a adjacency graph
        vector<vector<int>> um(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    um[i].push_back(j);
                    um[j].push_back(i);
                }
            }
        }
        // ab dekho normal dfs wala code likh skte hai.
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,um,visited);
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    void dfs(int source,vector<vector<int>>& isConnected,vector<bool>& visited){
        visited[source]=true;
        // explore its neighbour;
        for(int j=0;j<isConnected[source].size();j++){
            // isConnected [i] [j] = 1 ye basically wha pe denote kr rha hai city
            if(!visited[j] && isConnected[source][j]==1){
                dfs(j,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                // jo bhi connected component hai usko mark kr dega.
                dfs(i,isConnected,visited);
                count++;
            }
        }
        return count;
    }
};
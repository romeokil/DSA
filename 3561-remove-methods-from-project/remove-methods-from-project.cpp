class Solution {
public:
    void dfs(int source,vector<bool>& visited,unordered_set<int>& suspicion,unordered_map<int,vector<int>>& um){
        visited[source]=true;
        suspicion.insert(source);
        for(const int &v:um[source]){
            if(!visited[v]){
                dfs(v,visited,suspicion,um);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> um;
        unordered_map<int,vector<int>> invokedby;
        vector<bool> visited(n,false);
        unordered_set<int> suspicion;
        // hmlog whi method ko uda skte the jo ki suspicion me involve ni tha
        // and ye hmlog information koi bhi bnda kisse invoked hua hai usi se nikal skte hai.
        // or result me aisa lounda aaega jo suspicion me involve ni tha.
        vector<int> result;
        for(const vector<int>& v:invocations){
            int invokekrnewala=v[0];
            int invokehonewala=v[1];
            um[invokekrnewala].push_back(invokehonewala);
            invokedby[invokehonewala].push_back(invokekrnewala);
        }

        dfs(k,visited,suspicion,um);

        // suspicion wala arrray me traverse maarte hai
        bool canRemove=true;
        for(const int &u:suspicion){
            for(const int &v:invokedby[u]){
                if(suspicion.find(v)==suspicion.end()){
                    canRemove=false;
                    break;
                }
            }
            if(!canRemove) break;
        }

        if(!canRemove){
            for(int i=0;i<n;i++){
                result.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(suspicion.find(i)==suspicion.end()) result.push_back(i);
            }
        }
        return result;
    }
};
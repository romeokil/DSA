class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int freshorangesCount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) freshorangesCount++;
            }
        }
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        // if There were no Fresh Oranges, then how you make them Rotten.
        if(freshorangesCount==0) return 0;
        while(!q.empty()){
            int size=q.size();
            bool pushOranges=false;
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();q.pop();
                int x=p.first;
                int y=p.second;
                for(vector<int> dir:directions){
                    int x_=x+dir[0];
                    int y_=y+dir[1];
                    if(x_>=0 && x_<n && y_>=0 && y_<m && grid[x_][y_]==1){
                        q.push({x_,y_});
                        grid[x_][y_]=2;
                        freshorangesCount--;
                        pushOranges=true;
                    }
                }
            }
            if(pushOranges) count++;
        }
        return freshorangesCount>0?-1:count; 
    }
};
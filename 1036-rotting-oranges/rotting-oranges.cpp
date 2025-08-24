class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       queue<pair<int,int>> q;
       vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
       int time=0;
       int freshOranges=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    freshOranges++;
                }
                // ye krna jaruri ni hai qki esme sayd ek hi sada hua hota hai but phir bhi
                // hm safety measure lene ke liye aisa kr liye.
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(freshOranges==0) return 0;
        while(!q.empty()){
            int size=q.size();
            bool sarahuanikla=false;
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();q.pop();
                int row=p.first;
                int col=p.second;
                for(auto it:directions){
                    int updatedrow=it.first+row;
                    int updatedcolumn=it.second+col;
                    if((updatedrow>=0 && updatedrow<n) && (updatedcolumn>=0 && updatedcolumn<m) && (grid[updatedrow][updatedcolumn]==1)){
                        q.push({updatedrow,updatedcolumn});
                        grid[updatedrow][updatedcolumn]=2;
                        sarahuanikla=true;
                    }
                }
            }
            if(sarahuanikla) time++;
            cout<<time<<endl;
        }
        int remainingfreshOranges=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    remainingfreshOranges++;
                    flag=true;
                }
            }
            if(flag) break;
        }
        return remainingfreshOranges!=0?-1:time;
    } 
};
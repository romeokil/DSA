class Solution {
public:
    void dfs(int sr,int sc,int n,int m,vector<vector<int>>& image,int originalcolor,int color){
        if(sr<0 || sr>=n || sc<0 || sc>=m || image[sr][sc]==color || image[sr][sc]!=originalcolor) return ;
        // agr kahi aisa ni hai toh 
        image[sr][sc]=color;
        dfs(sr,sc-1,n,m,image,originalcolor,color);
        dfs(sr,sc+1,n,m,image,originalcolor,color);
        dfs(sr-1,sc,n,m,image,originalcolor,color);
        dfs(sr+1,sc,n,m,image,originalcolor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalcolor=image[sr][sc];
        // if there is same color in the starting position as color.
        if(originalcolor==color) return image;
        // otherwise dfs start krte hai es position se.
        int n=image.size();
        int m=image[0].size();
        dfs(sr,sc,n,m,image,originalcolor,color);
        return image;
        

    }
};
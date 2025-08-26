class Solution {
public:
    void dfs(int row,int col,int color,int originalcolor,vector<vector<int>>& image){
        // pehle check kr lete hai ki bhai ye valid index toh hai na 
        // original color color ke equal toh ni hai na
        if(row<0 || row>=image.size() || col<0 || col>=image[0].size() || image[row][col]!=originalcolor || image[row][col] == color){
            return;
        }
        // mark kro given color se
        image[row][col]=color;
        dfs(row+1,col,color,originalcolor,image);
        dfs(row-1,col,color,originalcolor,image);
        dfs(row,col+1,color,originalcolor,image);
        dfs(row,col-1,color,originalcolor,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       if(image[sr][sc]==color) return image;
       int n=image.size();
       int m=image[0].size();
       int originalcolor=image[sr][sc];
       // marking the starting index
       dfs(sr,sc,color,originalcolor,image);
       return image;
    }
};
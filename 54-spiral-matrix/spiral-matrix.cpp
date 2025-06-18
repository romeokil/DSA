class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int rowstart=0,rowend=n-1,colstart=0,colend=m-1;
        vector<int> result;
        while(rowstart<=rowend && colstart<=colend){
            // horizontally left to right move krte hai.
            for(int i=colstart;i<=colend;i++){
                result.push_back(matrix[rowstart][i]);
            }
            rowstart++;
            // vertically top to bottom move krte hai.
            for(int j=rowstart;j<=rowend;j++){
                result.push_back(matrix[j][colend]);
            }
            colend--;
            if(rowstart>rowend || colstart>colend) break;
            // horizontally right to left move krte hai.
            for(int k=colend;k>=colstart;k--){
                result.push_back(matrix[rowend][k]);
            }
            rowend--;
            // vertically bottom to top move kr lege.
            for(int l=rowend;l>=rowstart;l--){
                result.push_back(matrix[l][colstart]);
            }
            colstart++;
        }
        return result;
    }
};
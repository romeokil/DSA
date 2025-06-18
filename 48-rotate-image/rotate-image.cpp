class Solution {
public:
    void display(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // without extra space
        // pehle transpose kr dete hai
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        display(matrix);
        // now meke the matrix opposite to get rotated image
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
        display(matrix);
    }
};
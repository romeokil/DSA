class Solution {
public:
    vector<vector<int>> generate(int numRows) {
            vector<vector<int>> matrix(numRows);
            for(int i=0;i<numRows;i++){
                vector<int> rowm(i+1,1);
            for(int j=1;j<i;j++){
                rowm[j]=matrix[i-1][j-1]+matrix[i-1][j];
                cout<<"i "<<i<<"j "<<j<<endl;
                cout<<rowm[j]<<endl;
            }
            matrix[i]=rowm;
        }
        return matrix;
    }
};
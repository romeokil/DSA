class Solution {
public:
    void reverse(string &s){
        int i=0,j=s.length()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
    int minInsertions(string s) {
        int n=s.length();
        int m=n;
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        string originalstring=s;
        reverse(s);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(originalstring[i-1]==s[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        int length_of_common_subs=t[n][m];
        return n-length_of_common_subs;
    }
};
class Solution {
public:
    void reverse(string& s){
        int i=0,j=s.length()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
    int longestPalindromeSubseq(string s) {
        string originalString=s;
        reverse(s);
        int n=originalString.length();
        int m=s.length();
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                t[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(originalString[i-1]==s[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};
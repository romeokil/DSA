class Solution {
public:
    string reverse(string &s){
        int i=0,j=s.length()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
    int solve(int m,int n,string &originalString,string &reversedString,vector<vector<int>>& dp){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        if(originalString[m-1]==reversedString[n-1]){
            return dp[m][n]=1+solve(m-1,n-1,originalString,reversedString,dp);
        }
        return dp[m][n]=max(solve(m-1,n,originalString,reversedString,dp),solve(m,n-1,originalString,reversedString,dp));
    }
    int longestPalindromeSubseq(string s) {
        string originalString=s;
        string reversedString=reverse(s);
        // cout<<"reversedString"<<reversedString<<endl;
        int m=originalString.length();
        int n=reversedString.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,originalString,reversedString,dp);
    }
};
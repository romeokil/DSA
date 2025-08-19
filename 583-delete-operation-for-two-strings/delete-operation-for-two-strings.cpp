class Solution {
public:
    int solve(int n,int m,string &word1,string &word2,vector<vector<int>>& dp){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(word1[n-1]==word2[m-1]){
            return dp[n][m]=1+solve(n-1,m-1,word1,word2,dp);
        }
        return dp[n][m]=max(solve(n-1,m,word1,word2,dp),solve(n,m-1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int length_of_lcs=solve(n,m,word1,word2,dp);
        int deletion_count=n-length_of_lcs;
        int insertion_count=m-length_of_lcs;
        return deletion_count+insertion_count;
    }
};
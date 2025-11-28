class Solution {
public:
    int solve(int i, int j, string& word1, string& word2,vector<vector<int>>& t) {
        if (i >= word1.length()) {
            return word2.length() - j;
        }
        if (j >= word2.length()) {
            return word1.length() - i;
        }
        if(t[i][j]!=-1) return t[i][j];
        if (word1[i] == word2[j]) {
            return t[i][j]=solve(i + 1, j + 1, word1, word2,t);
        } else {
            int insertOps = 1 + solve(i, j + 1, word1, word2,t);
            int deleteOps = 1 + solve(i + 1, j, word1, word2,t);
            int replaceOps = 1 + solve(i + 1, j + 1, word1, word2,t);
            return t[i][j]=min({insertOps, deleteOps, replaceOps});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        return solve(0, 0, word1, word2,t);
    }
};
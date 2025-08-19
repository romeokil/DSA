class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        int i = n, j = m;
        string temp = "";
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                temp.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (t[i - 1][j] > t[i][j - 1]) {
                    temp.push_back(str1[i-1]);
                    i--;
                } else
                {
                    temp.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            temp.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            temp.push_back(str2[j-1]);
            j--;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
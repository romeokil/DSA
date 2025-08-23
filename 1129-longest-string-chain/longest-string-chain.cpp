class Solution {
public:
    bool checkPredecessor(string &shorter,string &longer){
        int n=longer.length();
        int m=shorter.length();
        if((n-m)!=1) return false;
        int i=0,j=0;
        bool skipped=false;
        while(i<n && j<m){
            if(longer[i]==shorter[j]){
                i++;j++;
            }
            else{
                if(skipped) return false;
                skipped=true;
                i++;
            }
        }
        return true;
    }
    int solve(int i,vector<string>& words,int prevIndex,vector<vector<int>>& dp){
        if(i>=words.size()) return 0;
        if(dp[i][prevIndex+1]!=-1) return dp[i][prevIndex+1];
        int take_case=0,skip_case=0;
        if(prevIndex==-1 || checkPredecessor(words[prevIndex],words[i])){
            // cout<<"prev-> "<<prev<<" "<<"words->taken "<<words[i]<<endl;
            take_case=1+solve(i+1,words,i,dp);
        }
        skip_case=solve(i+1,words,prevIndex,dp);
        return dp[i][prevIndex+1]=max(take_case,skip_case);
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](const string& a,const string& b){
            return a.size()<b.size();
        });
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,words,-1,dp);
    }
};
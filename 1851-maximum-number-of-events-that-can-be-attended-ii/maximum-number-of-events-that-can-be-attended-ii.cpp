class Solution {
public:
    int solve(int index,vector<vector<int>>& events,int k,vector<vector<int>>& dp){
        if(index>=events.size() || k==0){
            return 0;
        }
        if(dp[index][k]!=-1) return dp[index][k];
        int startday=events[index][0];
        int endday=events[index][1];
        int value=events[index][2]; 
        int take_case=0,skip_case=0;
        skip_case=solve(index+1,events,k,dp);
        // ab agr take case ke liye lena hai toh hmlog ko toh fir hmlog linear search maar 
        // ke doondh lege.
        int j=index+1;
        for(;j<events.size();j++){
            if(events[j][0]>endday){
                break;
            }
        }
        take_case=value+solve(j,events,k-1,dp);
        return dp[index][k]=max(take_case,skip_case);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,events,k,dp);
    }
};
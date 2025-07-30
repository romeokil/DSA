class Solution {
public:
    bool solve(int current_stone_idx,vector<int>& stones,int prev_jump,unordered_map<int,int>& um,vector<vector<int>> &dp){
        if(current_stone_idx==stones.size()-1){
            return true;
        }
        if(dp[current_stone_idx][prev_jump]!=-1) return dp[current_stone_idx][prev_jump];
        // hmlogo ke pass 3 option hai.
        bool result=false;
        for(int next_jump=prev_jump-1;next_jump<=prev_jump+1;next_jump++){
            // aisa eslie likhe ki negative ya 0 jump maarke kaha hi chal jaega tm.
            if(next_jump>0){
                int next_stone=stones[current_stone_idx]+next_jump;
                if(um.find(next_stone)!=um.end()){
                    result= result || solve(um[next_stone],stones,next_jump,um,dp);
                }
            }
        }
        return dp[current_stone_idx][prev_jump]=result;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            um[stones[i]]=i;
        }
        // current_stone_index jo 0 hai and prev_jump kitna maara.
        return solve(um[0],stones,0,um,dp);
    }
};
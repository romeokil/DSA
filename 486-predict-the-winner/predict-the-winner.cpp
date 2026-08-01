class Solution {
public:
    int solve(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        int take_i=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        // es type a question game strategy ka hota hai 
        // 2 baatein yaaad rkhna hai
        // apne liye best pick krna hai 
        // or opponent se minimum expect krna hai.
        int n=nums.size();
        int totalScore=accumulate(nums.begin(),nums.end(),0);
        int player1Score=solve(0,n-1,nums);
        int player2Score=totalScore-player1Score;
        if(player1Score>=player2Score) return true;
        return false;
    }
};
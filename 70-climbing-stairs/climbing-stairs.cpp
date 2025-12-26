class Solution {
public:
    int climbStairs(int n) {
        int totalSteps=0;
        if(n==0 || n==1 || n==2 ) return n;
        int prev=1,curr=2;
        for(int i=3;i<=n;i++){
            totalSteps=prev+curr;
            prev=curr;
            curr=totalSteps;
        }
        return totalSteps;
    }
};
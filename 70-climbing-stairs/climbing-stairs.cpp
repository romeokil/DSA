class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int curr=2,prev=1,next=0;
        for(int i=3;i<=n;i++){
            next=curr+prev;
            prev=curr;
            curr=next;
        }
        return next;
    }
};
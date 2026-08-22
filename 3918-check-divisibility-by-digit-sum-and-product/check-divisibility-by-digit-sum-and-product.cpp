class Solution {
public:
    bool checkDivisibility(int n) {
        int original_No=n;
        int sum=0,product=1;
        while(n!=0){
            int rem=n%10;
            sum+=rem;
            product*=rem;
            n/=10;
        }
        return (original_No%(sum+product)==0)?true:false;
    }
};
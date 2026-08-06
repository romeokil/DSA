class Solution {
public:
    int finddigitProduct(int no){
        int prod=1;
        while(no!=0){
            int rem=no%10;
            prod=prod*rem;
            no/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int digitProduct=finddigitProduct(i);
            if(digitProduct%t==0) return i;
        }
        return -1;
    }
};
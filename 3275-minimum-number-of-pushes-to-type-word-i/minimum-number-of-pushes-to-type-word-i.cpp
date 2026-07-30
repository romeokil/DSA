class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int ans=0;
        if(n<8) return n;
        int remainder=n%8, quotient=n/8;
        if(n>=8 && n<16){
            ans= 8+ (quotient+1)* remainder;
        }
        else if(n>=16 && n<24){
            ans= 24+ (quotient+1)* remainder;
        }
        else{
            ans=  48+ (quotient+1)* remainder;
        }
        return ans;
    }
};
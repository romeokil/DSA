class Solution {
public:
    int longestSubsequence(string s, int k) {
        int i=0;
        int length=0;
        int powervalue=1; // 2 ka power 0 se hi start hota hai na.
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            // agr 0 hai toh koi dikkat hi ni hai.
            if(s[i]=='0'){
                length++;
            }
            else if(powervalue<=k){
                length++;
                k=k-powervalue;
            }
            if(powervalue<=k){
                powervalue*=2;
            }
        }
        return length;
    }
};
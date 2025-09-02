class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int> prefixsumZero(n,0);
        if(s[0]=='0') prefixsumZero[0]=1;
        for(int i=1;i<n;i++){
            prefixsumZero[i]=prefixsumZero[i-1]+(s[i]=='0'?1:0);
        }
        vector<int> prefixsumOne(n,0);
        if(s[n-1]=='1') prefixsumOne[n-1]=1;
        for(int i=n-2;i>=0;i--){
            prefixsumOne[i]=prefixsumOne[i+1]+(s[i]=='1'?1:0);
        }
        int maxScore=0;
        for(int i=0;i<n-1;i++){
            int leftZerocount=prefixsumZero[i];
            int rightOnecount=prefixsumOne[i+1];
            maxScore=max(maxScore,leftZerocount+rightOnecount);
        }
        return maxScore;
    }
};
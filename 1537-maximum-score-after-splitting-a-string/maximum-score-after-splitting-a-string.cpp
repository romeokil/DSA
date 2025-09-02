class Solution {
public:
    int findZero(string s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') count++;
        }
        return count;
    }
    int findOne(string s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') count++;
        }
        return count;
    }
    int maxScore(string s) {
        int n=s.length();
        int maxScore=0;
        for(int i=0;i<n-1;i++){
            string leftstring=s.substr(0,i+1);
            string rightstring=s.substr(i+1,n-i-1);
            int countZeroes=findZero(leftstring);
            int countOnes=findOne(rightstring);
            maxScore=max(maxScore,countZeroes+countOnes);
        }
        return maxScore;
    }
};
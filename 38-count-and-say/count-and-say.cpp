class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string result=countAndSay(n-1);
        string newresult;
        for(int i=0;i<result.length();i++){
            char ch=result[i];
            int count=1;
            while(i<result.length()-1 && result[i]==result[i+1]){
                i++;
                count++;
            }
            newresult+=to_string(count)+string(1,ch);
        }
        return newresult;
    }
};
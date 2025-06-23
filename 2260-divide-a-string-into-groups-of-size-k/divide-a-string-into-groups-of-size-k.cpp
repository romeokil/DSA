class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string> result;
        for(int i=0;i<s.length();i+=k){
            if(i+k<=n){
                string temp=s.substr(i,k);
                result.push_back(temp);
            }
            else{
                string curr="";
                // bhiaya string se jo bhi character hai wo 
                // extract kr lo
                while(i<s.length()){
                    curr.push_back(s[i]);
                    i++;
                }
                // ab jo remaining bacha hai usko append kr do
                int remaining=k-curr.length();
                while(remaining>0){
                    curr.push_back(fill);
                    remaining--;
                }
                result.push_back(curr);
            }
        }
        return result;
    }
};
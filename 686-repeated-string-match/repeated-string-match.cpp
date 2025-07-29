class Solution {
public:
    bool check(string a,string b){
        int n=a.length();
        int m=b.length();
        for(int i=0;i<n;i++){
            int j;
            for(j=0;j<m;j++){
                if(a[i+j]!=b[j]){
                    break;
                }
            }
            if(j==m) return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int count=1;
        string temp="";
        temp=a;
        while(a.length()<b.length()){
            a=a+temp;
            count=count+1;
        }
        if(check(a,b)){
            return count;
        }
        a=a+temp;
        count=count+1;
        if(check(a,b)){
            return count;
        }
        return -1;
    }
};
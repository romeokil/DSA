class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int result=0;
        for(int i=0;i<n;i++){
            int press= (i/8+1);
            result=result+press;
        }
        return result;
    }
};
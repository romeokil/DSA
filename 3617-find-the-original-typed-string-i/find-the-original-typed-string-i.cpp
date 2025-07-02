class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]) count++;
        }
        // count+1 hm eslie kr rhe hai qki ek original string bhi ho skta hai mera answer
        // tb jb originally hmlog ni dbaana chah rhe hoge.
        return count+1;
    }
};
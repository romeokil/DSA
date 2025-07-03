class Solution {
public:
    char kthCharacter(int k) {
        string result="a";
        while(result.length()<k){
            string temp="";
            for(int i=0;i<result.length();i++){
                temp.push_back(char(result[i]+1));
            }
            result+=temp;
        }
        return result[k-1];
    }
};
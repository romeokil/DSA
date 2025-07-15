class Solution {
public:
    char tolower(char ch){
        // agr capital hai toh
        if(ch>='A' && ch<='Z'){
            return ch+32; 
        }
        return ch;
    }
    bool isalnum(char ch){
        return (ch>='a' && ch<='z') || (ch>='0' && ch<='9') || (ch>='A' && ch<='Z');
    }
    bool isvowel(char ch){
        ch=tolower(ch);
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    bool isconsonant(char ch){
        ch=tolower(ch);
        return !(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') && !(ch>='0' && ch<='9');
    }
    bool isValid(string word) {
        bool vowel=false,consonant=false;
        if(word.length()<3) return false;
        for(int i=0;i<word.length();i++){
            if(!isalnum(word[i])) return false;
            if(isvowel(word[i])){
                vowel=true;
            }
            else if(isconsonant(word[i])){
                cout<<"consonant ky hai ji"<<word[i]<<endl;
                consonant=true;
            }
        }
        return vowel && consonant;
    }
};
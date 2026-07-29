class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        string ans="";
        vector<int> freq(26,0);
        
        // updating the freq array.
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        
        // building the left string
        string left="";
        for(int i=0;i<26;i++){
            left+=string(freq[i]/2,'a'+i);
        }
        
        // building the middle string wo sure hai ek hi character hoga.
        string middle="";
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                middle+=char('a'+i);
            }
        }

        // building the right string
        string right=left;
        reverse(right.begin(),right.end());
        ans=left+middle+right;
        return ans;
    }
};
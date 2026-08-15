class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        int result=0;
        int k=2;
        unordered_map<char,int> um;
        while(j<n){
            um[s[j]]++;
            while(i<=j && um[s[j]]>k){
                um[s[i]]--;
                if(um[s[i]]==0) um.erase(s[i]);
                i++;
            }
            result=max(result,(j-i+1));
            j++;
        }
        return result;
    }
};
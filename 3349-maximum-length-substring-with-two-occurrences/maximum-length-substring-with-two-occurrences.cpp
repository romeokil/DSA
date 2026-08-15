class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        int k=2;
        for(int i=0;i<n;i++){
            unordered_map<int,int> um;
            for(int j=i;j<n;j++){
                um[s[j]]++;
                if(um[s[j]]>k) break;
                maxlen=max(maxlen,(j-i+1));
            }
        }
        return maxlen;
    }
};
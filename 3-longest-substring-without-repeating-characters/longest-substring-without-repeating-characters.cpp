class Solution {
public:
    bool checkOccurence(unordered_map<char,int> & um){
        for(const pair<char,int>& p:um){
            if(p.second>1) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> um;
        int maxlen=INT_MIN;
        int i=0,j=0;
        while(j<n){
            um[s[j]]++;
            while(i<j && checkOccurence(um)){
                um[s[i]]--;
                if(um[s[i]]==0) um.erase(s[i]);
                i++;
            }
            maxlen=max(maxlen,(j-i+1));
            j++;
        }
        return maxlen==INT_MIN?0:maxlen;
    }
};
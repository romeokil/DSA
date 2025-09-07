class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int p=strs.size();
        if(p==1) return strs[0];
        sort(strs.begin(),strs.end());
        string shorter=strs[0];
        string longer=strs[p-1];
        int n=shorter.length();
        int m=longer.length();
        int i=0,j=0;
        string result="";
        while(i<n && j<m){
            if(shorter[i]==longer[j]){
                result.push_back(shorter[i]);
            }
            else break;
            i++;j++;
        }
        return result;
    }
};